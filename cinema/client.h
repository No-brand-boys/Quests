#ifndef CINEMA_CLIENT_H
#define CINEMA_CLIENT_H

#define ROW 5
#define COLUMN 10
#define ROOM 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *ACCOUNTS = "../account.txt";
const char *ROOMS = "../room.txt";
const char *BOOK = "../book.txt";

struct Film {
    int id;
    char name[100];
    bool seats[ROW][COLUMN]; // true ��ʾ�Ѿ�������
    tm startTime;
    int rest;
    double price;
};

struct Book {
    int filmID;
    int row;
    int column;
    char owner[100];
};

struct Account {
    char name[100];
    char pwd[100];
};

Account *account;
bool admin = false;

int count = 0; // �û��ĸ���
Account **accountList; // �û��б����ṹ������

int filmCount = 0;
Film** films;

int bookCount = 0;
Book **bookList;

void getFilms();

void loadBook();

int getLines(FILE *fp);

void initialize() {
    count = 0;
    FILE *fp = fopen(ACCOUNTS, "r");

    if (fp == nullptr) {
        printf("No such file\n");
        exit(2);
    }
    count = getLines(fp);
    accountList = (Account **) calloc(count, sizeof(void *));
    for (int i = 0; i < count; ++i) {
        accountList[i] = (Account *) malloc(sizeof(Account));
        fscanf(fp, "%s %s\n", accountList[i]->name, accountList[i]->pwd);
    }
    fclose(fp);
    getFilms();
    loadBook();
}

int getLines(FILE *fp) {
    int n = 0;
    while (!feof(fp)) {
        char ch = fgetc(fp);
        if (ch == '\n') {
            n++;
        }
    }
    rewind(fp);
    return n;
}

void getFilms() {
    FILE *fp1 = fopen(ROOMS, "r");
    if (fp1 == nullptr) {
        printf("No such file\n");
        exit(2);
    }
    filmCount = getLines(fp1);
    films = (Film **)calloc(filmCount, sizeof(void *));
    for (int j = 0; j < filmCount; ++j) {
        films[j] = (Film *)malloc(sizeof(Film));
        films[j]->rest = ROW * COLUMN;
        fscanf(fp1, "%d %lf %s %d:%d\n", &films[j]->id, &films[j]->price, films[j]->name, &films[j]->startTime.tm_hour,
               &films[j]->startTime.tm_min);
        films[j]->rest = ROW * COLUMN;
    }
    fclose(fp1);
}

void loadBook() {
    bookCount = 0;
    FILE *fp = fopen(BOOK, "r");
    if (fp == nullptr) {
        printf("No such file\n");
        exit(2);
    }
    while (!feof(fp)) {
        char ch = fgetc(fp);
        if (ch == '\n') {
            bookCount++;
        }
    }
    rewind(fp);
    bookList = (Book **) calloc(bookCount, sizeof(void *));
    for (int i = 0; i < bookCount; ++i) {
        bookList[i] = (Book *) malloc(sizeof(Book));
        fscanf(fp, "%d %d %d %s\n", &bookList[i]->filmID, &bookList[i]->row, &bookList[i]->column, bookList[i]->owner);
        films[bookList[i]->filmID - 1]->seats[bookList[i]->row][bookList[i]->column] = true;
        films[bookList[i]->filmID - 1]->rest -= 1;
    }
    fclose(fp);
}

void viewRoom(int index) {
    index -= 1;
    printf("ID: %d, �۸�: %.2lf\n", films[index]->id, films[index]->price);
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            if (!films[index]->seats[i][j]) {
                putchar('_');
            } else {
                putchar('@');
            }
        }
        printf("\n");
    }
}

void view() {
    for (int i = 0; i < filmCount; ++i) {
        printf("��Ӱ��ţ�%d �����ţ�%d ��Ӱ���ƣ�%s ��ӳʱ�䣺%2d:%2d ��Ʊ��%d �۸�%.2lf\n", i, films[i]->id, films[i]->name, films[i]->startTime.tm_hour,
               films[i]->startTime.tm_min, films[i]->rest, films[i]->price);
    }
    printf("\n");
}

void buy() {
    int index = 0;
    printf("�������Ӱ�ı�ţ�\n");
    scanf("%d", &index);
    if (index < 1 || index > ROOM) {
        printf("invalid input!\n");
        return;
    }
    int row = 0;
    int column = 0;
    printf("�������кţ�\n");
    scanf("%d", &row);
    if (row < 0 || row > ROW) {
        printf("invalid input!\n");
        return;
    }
    printf("�������кţ�\n");
    if (column < 0 || column > COLUMN) {
        printf("invalid input!\n");
        return;
    }
    scanf("%d", &column);
    if (films[index - 1]->seats[row][column]) {
        printf("��λ���ѱ�����");
        return;
    } else {
        FILE *fp = fopen(BOOK, "a");
        fprintf(fp, "%d %d %d %s\n", index, row, column, account->name);
        fclose(fp);
        loadBook();
        printf("��Ʊ�ɹ���");
    }
}

void retire() {
    int index = 0;
    printf("�������Ӱ�ı�ţ�\n");
    scanf("%d", &index);
    FILE *fp = fopen(BOOK, "w");
    printf("���ƣ�%s ʱ�䣺%2d:%2d\n", films[index]->name, films[index]->startTime.tm_hour, films[index]->startTime.tm_min);
    printf("�Ƿ�ȷ���˶���������1�˶���\n");
    int temp = 0;
    scanf("%d", &temp);
    if(temp != 1) {
        printf("ȡ���˶���\n");
        return;
    }
    for (int i = 0; i < bookCount; ++i) {
        if (strcmp(bookList[i]->owner, account->name) == 0 && bookList[i]->filmID == index) {
            continue;
        }
        fprintf(fp, "%d %d %d %s\n", bookList[i]->filmID, bookList[i]->row, bookList[i]->column, bookList[i]->owner);
    }
    fclose(fp);
    printf("��Ʊ�ɹ���\n");
    loadBook();
}

#endif //CINEMA_CLIENT_H

#ifndef RECITE_MODEL_H
#define RECITE_MODEL_H

#include <stdio.h>
#include <cstdlib>
#include <stdint.h>

struct Word {
    char eng[100];
    char figure[20];
    char chn[100];
};

struct Account {
    char name[100];
    char pwd[100];
};

const char *WORD_PATH = "../words.txt";
const char *ACCOUNT_PATH = "../accounts.txt";
size_t wordCount;
Word **wordList;
size_t accountNumber;
Account **accountList;

size_t getLines(FILE *fp) {
    size_t line = 0;
    if (fp == nullptr) {
        throw 1;
    }
    do {
        int c = fgetc(fp);
        if (c == '\n') {
            line++;
        }
    } while (!feof(fp));
    rewind(fp);
    return line;
}


void loadData() {
    FILE *fp = fopen(WORD_PATH, "r");
    wordCount = getLines(fp);
    wordList = (Word **) calloc(wordCount, sizeof(void *));
    for (int i = 0; i < wordCount; ++i) {
        wordList[i] = (Word *) malloc(sizeof(Word));
        fscanf(fp, "%s %s %s\n", wordList[i]->eng, wordList[i]->figure, wordList[i]->chn);
    }
    fclose(fp);

    FILE *fp1 = fopen(ACCOUNT_PATH, "r");
    accountNumber = getLines(fp1);
    accountList = (Account **)calloc(accountNumber, sizeof(void *));
    for (int j = 0; j < accountNumber; ++j) {
        accountList[j] = (Account *)calloc(accountNumber, sizeof(Account));
        fscanf(fp, "%s %s\n", accountList[j]->name, accountList[j]->pwd);
    }

}

#endif //RECITE_MODEL_H

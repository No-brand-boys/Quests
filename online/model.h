#ifndef ONLINE_MODEL_H
#define ONLINE_MODEL_H

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "util.h"

const char *ACCOUNT_PATH = "../account.txt";
const char *LOG_PATH = "../log.txt";
const char *OUTPUT = "../output.txt";

struct Account {
    int id;
    char name[40];
    int category;
    double cost;
};

struct Log {
    int id;
    tm from;
    tm to;
};

int accountNumber = 0;
Account **accountList;

int logNumber = 0;
Log **logList;

void getCost(Account *account);

/**
 * ��ȡһ���ļ��ܹ������У���ȷ�����鴴�����ٸ�Ԫ��
 *
 * @param fp ָ����ļ�
 * @return ����
 */
int getLines(FILE *fp) {
    int count = 0;
    char ch = 0;
    while (!feof(fp)) {
        ch = fgetc(fp);
        if (ch == '\n') {
            count++;
        }
    }
    rewind(fp);
    return count;
}

/**
 * ��ʼ�����ݣ�����accountList��logList���ö�̬����ķ�ʽ��������֤���ᱻ�����β����٣����ҽ�Լ�˿ռ�
 * �����е�ÿ��Ԫ�ض���һ��ָ�룬ָ��ṹ�壬�����޸�����
 * malloc��calloc��������Դ��stdlib.h
 */
void load() {
    logNumber = 0;
    accountNumber = 0;
    FILE *fp = fopen(ACCOUNT_PATH, "r");
    FILE *fp1 = fopen(LOG_PATH, "r");
    if (fp == nullptr || fp1 == nullptr) {
        printf("No such file");
        throw 2;
    }
    accountNumber = getLines(fp);
    accountList = (Account **) calloc(accountNumber, sizeof(void *));
    for (int i = 0; i < accountNumber; ++i) {
        accountList[i] = (Account *) malloc(sizeof(Account));
        fscanf(fp, "%d %s %d\n", &accountList[i]->id, accountList[i]->name, &accountList[i]->category);
    }

    logNumber = getLines(fp1);
    logList = (Log **) calloc(logNumber, sizeof(void *));
    for (int j = 0; j < logNumber; ++j) {
        logList[j] = (Log *) malloc(sizeof(Log));
        fscanf(fp1, "%d %4d%2d%2d%2d%2d%2d %4d%2d%2d%2d%2d%2d\n", &logList[j]->id,
               &logList[j]->from.tm_year, &logList[j]->from.tm_mon, &logList[j]->from.tm_mday,
               &logList[j]->from.tm_hour, &logList[j]->from.tm_min, &logList[j]->from.tm_sec,
               &logList[j]->to.tm_year, &logList[j]->to.tm_mon, &logList[j]->to.tm_mday,
               &logList[j]->to.tm_hour, &logList[j]->to.tm_min, &logList[j]->to.tm_sec
        );
    }
    for (int k = 0; k < accountNumber; ++k) {
        accountList[k]->cost = 0;
        getCost(accountList[k]);
    }
}

void showLog(Log *log) {
    printf("%04d %04d%02d%02d%02d%02d%02d %04d%02d%02d%02d%02d%02d\n", log->id,
           log->from.tm_year, log->from.tm_mon, log->from.tm_mday,
           log->from.tm_hour, log->from.tm_min, log->from.tm_sec,
           log->to.tm_year, log->to.tm_mon, log->to.tm_mday,
           log->to.tm_hour, log->to.tm_min, log->to.tm_sec
    );
}

/**
 * ��һ���ļ���д��һ��account����Ϣ
 *
 * @param account ��Ҫд��Ĳ���
 * @param fp д����ļ�ָ��
 */
void printAccount(Account *account, FILE *fp) {
    fprintf(fp, "%04d %s %d %.2lf", account->id, account->name, account->category, account->cost);
}

/**
 * ��ʱ��ṹ��ת��Ϊʱ��������ڼ���ʱ���
 *
 * @param t1 ʱ��ṹ��
 * @return ʱ���Ӧ��ʱ���
 */
time_t getStamp(tm t1) {
    t1.tm_year -= 1900;
    t1.tm_mon -= 1;
    return mktime(&t1);
}

double calc(int min, int category) {
    switch (category) {
        case 0:
            return min * 0.03;
        case 1:
            return 50 + (min - 1800) * 0.03;
        case 2:
            return 95 + (min - 3600) * 0.03;
        case 3:
            return 200 + (min - 9000) * 0.03;
        case 4:
            return 300;
        default:
            printf("%s", strerror(1));
            throw 1;
    }
}

void getCost(Account *account) {
    int minTime = 0;
    for (int i = 0; i < logNumber; ++i) {
        if (logList[i]->id == account->id) {
            minTime += (int) ceil((double) (getStamp(logList[i]->to) - getStamp(logList[i]->from)) / 60);
        }
    }
    account->cost = calc(minTime, account->category);
}

void queryCost() {
    int id = atoi(input("�������û�ID:\n"));
    for (int i = 0; i < accountNumber; ++i) {
        if (accountList[i]->id == id) {
            printf("�û�ID:%04d �û�����:%s, ����:%.2lf\n", accountList[i]->id, accountList[i]->name, accountList[i]->cost);
        }
    }
}

void getFullLog() {
    int id = atoi(input("�������û�ID:\n"));
    for (int i = 0; i < logNumber; ++i) {
        if (logList[i]->id == id) {
            printf("�û�ID: %04d\n", id);
            printf("��ʼʱ�䣺%04d��%02d��%02d��%02dʱ%02d��%02d��\n"
                   "����ʱ�䣺%04d��%02d��%02d��%02dʱ%02d��%02d��\n",
                   logList[i]->from.tm_year, logList[i]->from.tm_mon, logList[i]->from.tm_mday,
                   logList[i]->from.tm_hour, logList[i]->from.tm_min, logList[i]->from.tm_sec,
                   logList[i]->to.tm_year, logList[i]->to.tm_mon, logList[i]->to.tm_mday, logList[i]->to.tm_hour,
                   logList[i]->to.tm_min, logList[i]->to.tm_sec
            );
        }
    }
}

void output() {
    FILE *fp = fopen(OUTPUT, "w");

    int year = atoi(input("��������ݣ�"));
    int month = atoi(input("�������·ݣ�"));
    for (int j = 0; j < logNumber; ++j) {
        if (logList[j]->from.tm_year == year && logList[j]->from.tm_mon == month &&
            logList[j]->to.tm_year == year && logList[j]->to.tm_mon == month) {
            for (int i = 0; i < accountNumber; ++i) {
                if (accountList[i]->id == logList[j]->id) {
                    fprintf(fp, "%04d %s %d %.2lf\n", accountList[i]->id,
                            accountList[i]->name, accountList[i]->category, accountList[i]->cost);
                }
            }
        }
    }

    fclose(fp);
    printf("�Ʒ���Ϣ�ѱ��浽%s\n", OUTPUT);
}

void addLog() {
    FILE *fp = fopen(LOG_PATH, "a");
    int id = atoi(input("�������û�ID\n"));
    printf("��������ʼʱ�䣨��ʽͬlog.txt��");
    tm t1;
    scanf("%4d%2d%2d%2d%2d%2d", &t1.tm_year, &t1.tm_mon, &t1.tm_mday, &t1.tm_hour, &t1.tm_min, &t1.tm_sec);
    printf("���������ʱ�䣨��ʽͬlog.txt��");
    tm t2;
    scanf("%4d%2d%2d%2d%2d%2d", &t2.tm_year, &t2.tm_mon, &t2.tm_mday, &t2.tm_hour, &t2.tm_min, &t2.tm_sec);
    fprintf(fp, "%04d %04d%02d%02d%02d%02d%02d %04d%02d%02d%02d%02d%02d\n", id,
            t1.tm_year, t1.tm_mon, t1.tm_mday,
            t1.tm_hour, t1.tm_min, t1.tm_sec,
            t2.tm_year, t2.tm_mon, t2.tm_mday,
            t2.tm_hour, t2.tm_min, t2.tm_sec
    );
    fclose(fp);

}

#endif //ONLINE_MODEL_H

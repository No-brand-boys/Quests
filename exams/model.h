#ifndef EXAMS_MODEL_H
#define EXAMS_MODEL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

const char *SCORES = "../note.txt";
const char *OUTPUT = "../out.txt";

struct Score {
    char id[20];
    char name[40];
    double term;
    double mid;
    double fin;
    char rank;
    double total;
};

int stocks = 0;
Score **scoreList;

char classify(double score) {
    return score >= 90 ? 'A' :
           score >= 80 ? 'B' :
           score >= 70 ? 'C' :
           score >= 60 ? 'D' : 'E';
}

void load() {
    FILE *fp = fopen(SCORES, "r");
    if (fp == nullptr) {
        printf("%s", strerror(2));
        throw 2;
    }
    fscanf(fp, "%d\n", &stocks);
    scoreList = (Score **) calloc(stocks, sizeof(void *));
    for (int i = 0; i < stocks; ++i) {
        scoreList[i] = (Score *) malloc(sizeof(Score));
        fscanf(fp, "%s %s %lf %lf %lf\n", scoreList[i]->id, scoreList[i]->name,
               &scoreList[i]->term, &scoreList[i]->mid, &scoreList[i]->fin);
        scoreList[i]->total = scoreList[i]->term * 0.3 + scoreList[i]->mid * 0.3 + scoreList[i]->fin * 0.4;
        scoreList[i]->rank = classify(scoreList[i]->total);
    }
}

void formatPrint(Score *score) {
    printf("%s %s %lf %.2lf %.2lf %.2lf %c\n", score->id, score->name,
           score->term, score->mid, score->fin, score->total, score->rank);
}

void putScores() {
    printf("学号\t   姓名\t\t总分\n");
    for (int i = 0; i < stocks; ++i) {
        printf("%-10s %-10s %.2lf\n", scoreList[i]->id, scoreList[i]->name, scoreList[i]->total);
    }
    printf("\n");
}

void putAverage() {
    double avg = 0;
    for (int i = 0; i < stocks; ++i) {
        avg += scoreList[i]->total;
    }
    avg /= stocks;
    printf("班级的平均成绩为：%.2lf\n", avg);
}

void putLevel() {
    int a[5] = {0};
    for (int i = 0; i < stocks; ++i) {
        switch (scoreList[i]->rank) {
            case 'a':
            case 'A':
                a[0]++;
                break;
            case 'b':
            case 'B':
                a[1]++;
                break;
            case 'c':
            case 'C':
                a[2]++;
                break;
            case 'd':
            case 'D':
                a[3]++;
                break;
            case 'e':
            case 'E':
                a[4]++;
                break;
            default:
                printf("%s", strerror(1));
                return;
        }
    }
    printf("等级为优的学生人数：%2d，占比为%.2lf\n", a[0], a[0] * 1.0 / stocks);
    printf("等级为良的学生人数：%2d，占比为%.2lf\n", a[1], a[1] * 1.0 / stocks);
    printf("等级为中的学生人数：%2d，占比为%.2lf\n", a[2], a[2] * 1.0 / stocks);
    printf("等级为及格的学生人数：%2d，占比为%.2lf\n", a[3], a[3] * 1.0 / stocks);
    printf("等级为不及格的学生人数：%2d，占比为%.2lf\n", a[4], a[4] * 1.0 / stocks);
    printf("\n");
}

void viewLevel() {
    char ch = 0;
    ch = *input("请输入要查看的等级\n");
    printf("学号\t  成绩\t等级\n");
    FILE *fp = fopen(OUTPUT, "w");
    for (int i = 0; i < stocks; ++i) {
        if (scoreList[i]->rank == ch || scoreList[i]->rank == ch - 32) {
            printf("%-10s %-.2lf %c\n", scoreList[i]->id, scoreList[i]->total, scoreList[i]->rank);
            fprintf(fp, "%-10s %-.2lf %c\n", scoreList[i]->id, scoreList[i]->total, scoreList[i]->rank);
        }
    }
    printf("\n");
}

#endif //EXAMS_MODEL_H

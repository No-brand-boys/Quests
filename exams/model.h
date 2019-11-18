#ifndef EXAMS_MODEL_H
#define EXAMS_MODEL_H

#include <stdio.h>
#include <stdlib.h>

const char *SCORES = "../node.txt";
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
           score >= 60 ? 'D' : 'F';
}

void load() {
    FILE *fp = fopen(SCORES, "r");
    if (fp == nullptr) {
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

void prettyPrint(Score *score) {
    printf("%s %s %lf %lf %lf %lf %c\n", score->id, score->name,
           score->term, score->mid, score->fin, score->total, score->rank);
}

#endif //EXAMS_MODEL_H

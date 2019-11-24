#ifndef CINEMA_ADMIN_H
#define CINEMA_ADMIN_H

#include "client.h"

double viewFetch(int index) {
    return ((ROW * COLUMN) - films[index - 1]->rest) * films[index - 1]->price;
}

void sortRoom() {
    Film *sortedList[filmCount];
    double fetches[filmCount];
    Film *temp;
    double d;

    for (int i = 0; i < filmCount; ++i) {
        sortedList[i] = films[i];
        fetches[i] = viewFetch(films[i]->id);
    }
    for (int j = 0; j < filmCount; ++j) {
        for (int i = j; i < filmCount; ++i) {
            if (fetches[i] > fetches[j]) {
                temp = sortedList[i];
                sortedList[i] = sortedList[j];
                sortedList[j] = temp;
                d = fetches[i];
                fetches[i] = fetches[j];
                fetches[j] = d;
            }
        }
    }

    for (int k = 0; k < filmCount; ++k) {
        printf("ID: %d, �۳�: %d��Ʊ��: %.2lf\n", sortedList[k]->id, ROW * COLUMN - sortedList[k]->rest, fetches[k]);
    }
}

void updateFilm(int index) {
    index -= 1;
    printf("�������Ӱ�۸�");
    scanf("%lf", &films[index]->price);
    printf("�������Ӱ���ƣ�");
    scanf("%s", films[index]->name);
    printf("�������Ӱ��ʼʱ��(hh:mm)��");
    scanf("%d:%d", &films[index]->startTime.tm_hour, &films[index]->startTime.tm_min);

    FILE *fp = fopen(ROOMS, "w");
    for (int i = 0; i < filmCount; ++i) {
        fprintf(fp, "%d %.2lf %s %2d:%2d", films[i]->id, films[i]->price, films[i]->name, films[i]->startTime.tm_hour,
                films[i]->startTime.tm_min);
    }
    fclose(fp);

}

void addFilm() {
    Film *film = (Film *) malloc(sizeof(film));
    FILE *fp = fopen(ROOMS, "a");
    printf("�������Ӱ��ӳ�ķ��䣺");
    scanf("%d", &film->id);
    printf("�������Ӱ�۸�");
    scanf("%lf", &film->price);
    printf("�������Ӱ���ƣ�");
    scanf("%s", film->name);
    printf("�������Ӱ��ʼʱ��(hh:mm)��");
    scanf("%d:%d", &film->startTime.tm_hour, &film->startTime.tm_min);
    fprintf(fp, "%d %.2lf %s %2d:%2d\n", film->id, film->price, film->name, film->startTime.tm_hour,
            film->startTime.tm_min);
    fclose(fp);
    printf("�޸ĳɹ���\n");
}

void removeFilm() {
    int index = 0;
    printf("������Ҫ�Ƴ��ĵ�Ӱ��ţ�");
    scanf("%d", &index);
    FILE *fp = fopen(ROOMS, "w");
    for (int i = 0; i < filmCount; ++i) {
        if (i == index) {
            continue;
        }
        fprintf(fp, "%d %.2lf %s %2d:%2d\n", films[i]->id, films[i]->price, films[i]->name, films[i]->startTime.tm_hour,
                films[i]->startTime.tm_min);
    }
    fclose(fp);
    printf("�Ƴ��ɹ���\n");
}

void adminBoard() {
    int choice = 0;
    while (true) {
        int index = 0;
        printf("1. ��ѯ����Ʊ��\n2. �Ե����Ʊ����������\n3. �޸ĵ�Ӱ��Ϣ\n4. ���ӵ�Ӱ\n5. ɾ����Ӱ\n6. �鿴��Ӱ��Ϣ\n0. ����\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("������Ҫ�鿴�ĵ�ӰID\n");
                scanf("%d", &index);
                if (index <= 0 || index > filmCount) {
                    printf("invalid input!\n");
                    break;
                }
                printf("�õ�Ӱ��Ʊ����%.2lf\n", viewFetch(index));
                break;
            case 2:
                sortRoom();
                break;
            case 3:
                printf("������Ҫ�鿴�ĵ�ӰID\n");
                scanf("%d", &index);
                if (index <= 0 || index > filmCount) {
                    printf("invalid input!\n");
                    break;
                }
                updateFilm(index);
                break;
            case 4:
                addFilm();
                break;
            case 5:
                removeFilm();
                break;
            case 6:
                view();
            case 0:
                free(account);
                admin = false;
                account = nullptr;
                return;
            default:
                throw 1;
        }
    }
}

#endif //CINEMA_ADMIN_H

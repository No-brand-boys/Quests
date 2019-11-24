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
        printf("ID: %d, 售出: %d，票房: %.2lf\n", sortedList[k]->id, ROW * COLUMN - sortedList[k]->rest, fetches[k]);
    }
}

void updateFilm(int index) {
    index -= 1;
    printf("请输入电影价格：");
    scanf("%lf", &films[index]->price);
    printf("请输入电影名称：");
    scanf("%s", films[index]->name);
    printf("请输入电影开始时间(hh:mm)：");
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
    printf("请输入电影放映的房间：");
    scanf("%d", &film->id);
    printf("请输入电影价格：");
    scanf("%lf", &film->price);
    printf("请输入电影名称：");
    scanf("%s", film->name);
    printf("请输入电影开始时间(hh:mm)：");
    scanf("%d:%d", &film->startTime.tm_hour, &film->startTime.tm_min);
    fprintf(fp, "%d %.2lf %s %2d:%2d\n", film->id, film->price, film->name, film->startTime.tm_hour,
            film->startTime.tm_min);
    fclose(fp);
    printf("修改成功！\n");
}

void removeFilm() {
    int index = 0;
    printf("请输入要移除的电影编号：");
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
    printf("移除成功！\n");
}

void adminBoard() {
    int choice = 0;
    while (true) {
        int index = 0;
        printf("1. 查询当天票款\n2. 对当天的票房进行排序\n3. 修改电影信息\n4. 增加电影\n5. 删除电影\n6. 查看电影信息\n0. 返回\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("请输入要查看的电影ID\n");
                scanf("%d", &index);
                if (index <= 0 || index > filmCount) {
                    printf("invalid input!\n");
                    break;
                }
                printf("该电影的票房是%.2lf\n", viewFetch(index));
                break;
            case 2:
                sortRoom();
                break;
            case 3:
                printf("请输入要查看的电影ID\n");
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

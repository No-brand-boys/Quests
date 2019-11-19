#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// 所有时间结构体了列表
tm *tList;
// 数量
int stocks = 0;

/**
 * 判断某个时间是否在另一个时间之后
 * 最好的方法是转为timestamp再比较，但是msvc功能不支持
 */
bool before(tm t1, tm t2) {
    return t1.tm_year < t2.tm_year ? true : t1.tm_year > t2.tm_year ? false :
                                            t1.tm_mon < t2.tm_mon ? true : t1.tm_mon > t2.tm_mon ? false :
                                                                           t1.tm_yday < t2.tm_yday;
}

/**
 * 判断当前时间是否合法
 *
 * @param t 时间结构体
 * @return 是否为合法时间
 */
bool valid(tm t) {
    if (t.tm_mon < 1 || t.tm_mon > 12) {
        return false;
    }
    switch (t.tm_mon) {
        case 2:
            return t.tm_yday > 0 && t.tm_yday < 30;
        case 4:
        case 6:
        case 9:
        case 11:
            return t.tm_yday > 0 && t.tm_yday < 31;
        default:
            return t.tm_yday > 0 && t.tm_yday < 32;
    }
}

/**
 * 对列表进行排序，一个简单的选择排序
 */
void sort() {
    tm temp{};
    for (int i = 0; i < stocks; ++i) {
        for (int j = i; j < stocks; ++j) {
            if (before(tList[i], tList[j])) {
                memcpy(&temp, tList + i, sizeof(tm));
                memcpy(tList + i, tList + j, sizeof(tm));
                memcpy(tList + j, &temp, sizeof(tm));
            }
        }
    }
}

int main() {
    scanf("%d", &stocks);
    if (stocks <= 0) {
        printf("%s", strerror(1));
        throw 1;
    }
    tList = (tm *) calloc(stocks, sizeof(tm)); // 动态数组空间
    for (int i = 0; i < stocks; ++i) {
        scanf("%d %d %d", &tList[i].tm_year, &tList[i].tm_mon,
              &tList[i].tm_yday);
        if (!valid(tList[i])) {
            printf("invalid input!\n");
            i--;
        }
    }
    sort();
    printf("%04d_%02d_%02d\n", tList[1].tm_year, tList[1].tm_mon, tList[1].tm_yday);
    return 0;
}


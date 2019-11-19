#include <stdio.h>
#include <conio.h>

#include "model.h"
#include "utils.h"

void dashboard();

int main() {
    load();
    dashboard();
    return 0;
}

void dashboard() {
    int choice = 0;
    while (true) {
        printf("\n");
        choice = atoi(input("1. 计算每位学生的总评成绩\n2. 计算班级本课程总评成绩\n"
                            "3. 统计优、良、中、及格、不及格的学生人数以及所占比例\n4. 查询成绩在优、良、中、及格、不及格各区间的学生学号\n"
                            "5. 查看详细信息\n0. 退出\n"));
        switch (choice) {
            case 1:
                putScores();
                break;
            case 2:
                putAverage();
                break;
            case 3:
                putLevel();
                break;
            case 4:
                viewLevel();
                break;
            case 5:
                for (int i = 0; i < stocks; ++i) {
                    formatPrint(scoreList[i]);
                }
                break;
            case 0:
                return;
            default:
                printf("invalid input\n");
                continue;
        }
//        system("pause");
    }
}
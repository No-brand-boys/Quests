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
        choice = atoi(input("1. ����ÿλѧ���������ɼ�\n2. ����༶���γ������ɼ�\n"
                            "3. ͳ���š������С����񡢲������ѧ�������Լ���ռ����\n4. ��ѯ�ɼ����š������С����񡢲�����������ѧ��ѧ��\n"
                            "5. �鿴��ϸ��Ϣ\n0. �˳�\n"));
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
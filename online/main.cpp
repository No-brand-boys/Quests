#include <stdio.h>
#include <time.h>

#include "model.h"
#include "util.h"

void dashboard();

/**
 * ��ָ��һ��ʹ��nullptr����ʹ��NULL����ΪNULL�����ܣ����°�ı������лᱨwarning
 * throw��ʾ�ó�������������ϲ���Ļ�����exit(1)֮���
 * atoi��ʾ���ַ�������Ϊ���֣��޷������ķ���0���ú�����Դ��stdlib.h
 * �������������ĸ�ʽ���⣬����ֱ�Ӳ��
 */
int main() {
    load();
    dashboard();
    return 0;
}

/**
 * ���˵�
 */
void dashboard() {
    int choice = 0;
    while (true) {
        choice = atoi(input("1. ��ѯĳ���û��Ļ���\n2. ��ѯĳ���û���������¼\n3. ����˵�\n"
                            "4. ����һ����¼\n5. �˳�\n"));
        switch (choice) {
            case 1:
                queryCost();
                break;
            case 2:
                getFullLog();
                break;
            case 3:
                output();
                break;
            case 4:
                addLog();
                break;
            case 5:
                return;
            default:
                printf("invalid input!\n");
                continue;
        }
    }

}

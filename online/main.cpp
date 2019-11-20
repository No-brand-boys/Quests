#include <stdio.h>
#include <time.h>

#include "model.h"
#include "util.h"

void dashboard();

/**
 * 空指针一律使用nullptr，不使用NULL，因为NULL不严密，在新版的编译器中会报warning
 * throw表示让程序立即报错，不喜欢的话换成exit(1)之类的
 * atoi表示把字符串解析为数字，无法解析的返回0，该函数来源于stdlib.h
 * 关于输入和输出的格式问题，建议直接查表
 */
int main() {
    load();
    dashboard();
    return 0;
}

/**
 * 主菜单
 */
void dashboard() {
    int choice = 0;
    while (true) {
        choice = atoi(input("1. 查询某个用户的花费\n2. 查询某个用户的上网记录\n3. 输出账单\n"
                            "4. 增加一条记录\n5. 退出\n"));
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

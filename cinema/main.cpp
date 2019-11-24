#include <stdio.h>
#include <string.h>

#include "client.h"
#include "admin.h"

Account *login();
void userBoard();

int main() {
    initialize();
    while (account == nullptr) {
        login();
        view();
        if (admin) {
            adminBoard();
        } else {
            userBoard();
        }
    }
    return 0;
}

Account *login() {
    admin = false;
    account = (Account *) malloc(sizeof(Account));
    printf("input name(empty to exit):\n");
    setbuf(stdin, nullptr);
    if (scanf("%[^\n]", account->name) == 0) {
        exit(0);
    }
    printf("input password:\n");
    scanf("%s", account->pwd);
    for (int i = 0; i < count; ++i) {
        if (strcmp(account->name, accountList[i]->name) == 0 && strcmp(account->pwd, accountList[i]->pwd) == 0) {
            if (strcmp(account->name, "root") == 0) {
                admin = true;
            }
            return account;
        }
    }

    printf("��¼ʧ�ܣ�");
    return nullptr;
}

void userBoard() {
    int choice = 0;
    while (true) {
        int index = 0;
        printf("1. �����Ƭ��Ϣ\n2. ��Ʊ\n3. ��Ʊ\n0. ����\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("������Ҫ�鿴��ӰԺID\n");
                scanf("%d", &index);
                if (index <= 0 || index > ROOM) {
                    printf("invalid input!\n");
                    break;
                }
                viewRoom(index);
                break;
            case 2:
                buy();
                break;
            case 3:
                retire();
                break;
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

#include <stdio.h>

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
        choice = atoi(input("1. total score of student\n2. average score in class\n"
                            "3. calculate the number of each rank\n4. see who is in a certain rank\n"
                            "0. exit"));
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                return;
            default:
                printf("invalid input\n");
                continue;
        }
    }
}
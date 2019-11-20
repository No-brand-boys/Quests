#ifndef ONLINE_UTIL_H
#define ONLINE_UTIL_H

#include <stdio.h>
#include <stdlib.h>

/**
 * 把输入和输出合并起来，只是为了节省一些代码量，可以不使用
 *
 * @param hint 输出的提示内容
 * @return 键盘输入内容
 */
char *input(const char *hint) {
    char *content = (char *) calloc(100, sizeof(char));
    printf("%s\n", hint);
//    scanf("%[^\n]", content);
//    setbuf(stdin, nullptr);
    scanf("%s", content);
    return content;
}

#endif //ONLINE_UTIL_H

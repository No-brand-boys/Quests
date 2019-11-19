#ifndef EXAMS_UTILS_H
#define EXAMS_UTILS_H

#include <stdio.h>
#include <stdlib.h>

char *input(const char *hint) {
    char *content = (char *) calloc(100, sizeof(char));
    printf("%s\n", hint);
    scanf("%[^\n]", content);
    setbuf(stdin, nullptr);
    return content;
}

#endif //EXAMS_UTILS_H

#ifndef ONLINE_UTIL_H
#define ONLINE_UTIL_H

#include <stdio.h>
#include <stdlib.h>

/**
 * �����������ϲ�������ֻ��Ϊ�˽�ʡһЩ�����������Բ�ʹ��
 *
 * @param hint �������ʾ����
 * @return ������������
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

#include <algorithm.h>

int strlen(const char *s){
    int index=0;
    while(s[index] != '\0'){
        ++index;
    }
    return index;
}

int strcmp(const char *s1, const char* s2){
    while(*s1== *s2 && *s1 != '\0'){
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

char* strcpy(const char* str1, char* dest){
    char * ret = dest;
    while(*str1 != '\0'){
        *dest++ = *str1++;
    }
    *dest = '\0';
    return ret;
}

char* strcat(char* dst, const char* src){
    char* ret = dst;
    int len = strlen(dst);
    dst = dst+len;
    while(*src != '\0'){
        *dst++ = *src++;
    }
    *dst = '\0';
    return ret;
}

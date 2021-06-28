#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <vector>

using namespace std;

//template <typename T>
int binarySerch(vector<int>& arr, int val);
int hanoi(int num, char a, char b, char c);



//cstring
int strlen(const char *s);
int strcmp(const char *s1, const char* s2);
char* strcpy(const char* s, char* dest);
char* strcat(char* dst, const char* src);
#endif // ALGORITHM_H

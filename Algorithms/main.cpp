#include <iostream>
#include <algorithm.h>

using namespace std;

vector<int> arr{0,1,2,3,4,5,6,7,8,9};

void testBS(){
    int res = binarySerch(arr, 7);
    cout << res << endl;
}

void testDC(){
    hanoi(5, 'a', 'b','c');
}

void testString(){
    char str1[]= "1234";
    char str2[]= "5678";

    char* str3=strcat(str1, str2);

    cout << str3 << endl;
}

int main()
{
    testString();
    return 0;
}

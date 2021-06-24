#include <algorithm.h>

int count = 0;
int hanoi(int num, char a, char b, char c){
    if(num == 1){
        cout << a << "-->" << c << endl;
        count++;
    }else{
        hanoi(num-1, a, c, b);
        cout << a << "-->" << c << endl;
        count++;
        hanoi(num-1, b, a, c);
    }
        cout << count << endl;
}

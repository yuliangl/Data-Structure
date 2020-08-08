#include <iostream>
#include "dynamicstack.h"

using namespace std;

int main()
{
    dynamicStack stack;
    bool a = stack.isEmpty();
    cout<< "a: " << a << endl;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.traverse();

    stack.pop();
    cout<< "popValue: " << stack.popValue() << endl;
    stack.pop();
    cout<< "popValue: " << stack.popValue() << endl;
    stack.traverse();

    stack.push(5);
    stack.push(6);
    stack.traverse();

    return 0;
}

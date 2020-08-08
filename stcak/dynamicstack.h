#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

struct node{
    int value;
    node* next;
};

class dynamicStack
{
public:
    dynamicStack();
    ~dynamicStack();

    bool isEmpty();
    bool traverse();
    bool push(int);
    bool pop();
    int popValue(){return value;}

private:
    node *top;
    node *bottom;
    int value;
};

#endif // DYNAMICSTACK_H

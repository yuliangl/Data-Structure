#include <iostream>
#include "dynamicstack.h"


dynamicStack::dynamicStack():
    bottom(new node),
    value(0)
{
    top = bottom;
    top->next = nullptr;
}


bool dynamicStack::isEmpty(){
    if(top == bottom)
        return true;
    return false;
}

bool dynamicStack::traverse(){
    if(isEmpty()){
        std::cout<< "stack is empty. can not traverse." <<std::endl;
        return false;
    }
    node *pnew = new node;
    pnew = top;
    while (pnew != bottom) {
        std::cout<< pnew->value <<std::endl;
        pnew = pnew->next;
    }
    return true;
}

bool dynamicStack::push(int value){
    node *pnew = new node;
    pnew->next = top;
    pnew->value = value;
    top = pnew;

    return true;
}


bool dynamicStack::pop(){
    if(isEmpty())
        return false;
    node *pnew = new node;
    pnew = top;
    value = pnew->value;
    top = pnew->next;

    delete pnew;
    pnew = nullptr;

    return true;
}

dynamicStack::~dynamicStack(){
    if(isEmpty()){
        delete top;
        delete bottom;
    }

    while (!isEmpty()) {
        node *pnew = new node;
        pnew = top;
        top = pnew->next;
        delete pnew;
        pnew = nullptr;
    }

    delete top;
    delete bottom;
}

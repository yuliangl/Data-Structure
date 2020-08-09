#include "queue.h"
#include <iostream>

queue::queue(int len)
    :front(0),
    rear(0),
    length(len)
{
    base = new int(length);
}

queue::queue(queue &queue)
    :front(queue.front),
    rear(queue.rear),
    length(queue.length)
{
    base = new int(length);
    int i = front;
    while (i != rear) {
        base[i] = queue.base[i];
        i = (i+1)%length;
    }
}

queue& queue::operator=(queue &queue){
    front = queue.front;
    rear = queue.rear;
    length = queue.length;
    int *delBase = base;
    int *pBase = new int(length);
    base = pBase;
    int i = front;
    while (i != rear) {
        base[i] = queue.base[i];
        i = (i+1)%length;
    }
    delete delBase;
    return *this;
}

bool queue::enQueue(int value){
    if(isFull())
        return false;
    base[rear] = value;
    rear = (rear + 1)%length;

    return true;
}

bool queue::outQueue(){
    if(isEmpty())
        return false;
    value = base[front];
    front = (front+1)%length;
    return true;
}
bool queue::isEmpty(){
    if(front == rear){
        std::cout<< "the queue is empty."<<std::endl;
        return true;
    }
    return false;
}

bool queue::isFull(){
    if(front == (rear + 1)%length)
    {
        std::cout<< "the queue is fulled."<<std::endl;
        return true;
    }
    return false;
}

bool queue::traverse(){
    if(isEmpty())
        return false;
    int i = front;
    while (i != rear) {
        std::cout<< i << "is: " << base[i] <<std::endl;
    i = (i+1)%length;
    }
    return true;
}

queue::~queue(){
    delete []base;
}

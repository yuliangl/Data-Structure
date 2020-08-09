#ifndef QUEUE_H
#define QUEUE_H


class queue
{
public:
    explicit queue(int);
    queue(queue &);
    queue & operator = (queue &);
    ~queue();
    bool enQueue(int);
    bool outQueue();
    int outQueueValue() const {return value;}
    bool isEmpty();
    bool isFull();
    bool traverse();

private:
    int *base;
    int front;
    int rear;
    int length;
    int value;

};

#endif // QUEUE_H

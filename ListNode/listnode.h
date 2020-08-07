#ifndef LISTNODE_H
#define LISTNODE_H

struct node{
    node():value(0), next(nullptr){}
    ~node(){delete next;}
    int value;
    node *next;
};

class ListNode
{
public:
    ListNode();
    explicit ListNode(int len);
    ListNode(ListNode &);
    ListNode& operator =(ListNode &);
    ~ListNode();

    void traverse();
    void sort();
    int length();
    int index(node *);
    node* findNode(int);
    node* findLast(node *);
    bool insert(int, int);
    bool deleteNode(int);
    bool isEmpty();



private:
    node *head;
    node *tail;
    node *ptmp;
    node *pLast;
    node *pNext;
    int len;
    int value;

};

#endif // LISTNODE_H

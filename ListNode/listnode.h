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
    explicit ListNode(int len);
    void traverse(node *);
    void sort(node *);
    int length(node *);
    int index(node*, node *);
    node* findNode(node*,int);
    node* findLast(node*, node *);
    bool insert(node *, int, int);
    bool deleteNode(node *, int);
    bool isEmpty(node *);

    node *head;

    ~ListNode();


private:
    node *tail;
    node *ptmp;
    node *pLast;
    node *pNext;
    int len;
    int value;

};

#endif // LISTNODE_H

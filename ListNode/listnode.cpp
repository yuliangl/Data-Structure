#include "listnode.h"
#include <iostream>

ListNode::ListNode()
    :head(new node),
     tail(new node)
{
    head->next = nullptr;
    tail = head;

}

ListNode::ListNode(int len)
    :head(new node),
     tail(new node),
     ptmp(new node),
     pLast(new node),
     pNext(new node),
     len(len),
     value(0)
{   tail = head;
    tail->next = nullptr;
    for(int i=0; i<len; i++){
        node *pnew = new node;
        std::cout<< "input value please: ";
        std::cin>> value;
        pnew->value = value;
        tail->next = pnew;
        pnew->next = nullptr;
        tail = pnew;
    }
}

ListNode::ListNode(ListNode &ln){
    tail = head;
    for(int i=0; i<ln.length(); i++){
        node *pnew = new node;
        tail->next = pnew;
        pnew->value = ln.findNode(i)->next->value;
        pnew->next = nullptr;
        tail = pnew;
    }
}

inline ListNode&
ListNode::operator = (ListNode &ln){
    if(ln.length() != length()){
        std::cout<<" This operation is illegal because the ListNode lengths are different "
                <<std::endl;
        exit(1);
    }

    for(int i=0; i<length(); i++){
        findNode(i)->next->value = ln.findNode(i)->next->value;
    }
    return *this;
}

void ListNode::traverse(){
    if(isEmpty())
        std::cout<<"listnode is empty "<<std::endl;
    ptmp = head;
    while(ptmp->next != nullptr){
        std::cout << ptmp->next->value << std::endl;
        ptmp = ptmp->next;
    }
}

void ListNode::sort(){
    int i, j, tmp;
    int len = length();
    pLast=head->next;
    for(i=0,pLast=head->next; i<(len-1); i++,pLast=pLast->next)
    {
        for(j=i+1,pNext=pLast->next; j<len; j++,pNext=pNext->next)
        {
            if(pLast->value > pNext->value){
                tmp = pLast->value;
                pLast->value = pNext->value;
                pNext->value = tmp;

            }
        }
    }
}

int ListNode::length(){
    if(isEmpty())
        return 0;
    int i = 0;
    ptmp = head;
    while(ptmp->next != nullptr){
        i++;
        ptmp = ptmp->next;
    }
    return i;
}

bool ListNode::isEmpty(){
    if(head->next == nullptr)
        return true;
    return false;
}

int ListNode::index(node *current){
    if(isEmpty()){
        std::cout<<"listnode is empty"<<std::endl;
        return 0;
    }
    int leng = length();
    int index = 0;
    ptmp = head;

    for(int i=0; i<leng; i++){
        ptmp = ptmp->next;
        if (ptmp == current){
            index = i+1;
            break;
        }
    }
    return index;
}
node* ListNode::findNode(int index){
    if(index>length()){
        std::cout<<"index is over length"<<std::endl;
        return 0;
    }
    ptmp = head;
    for(int i=0;i<index; i++)
        ptmp = ptmp->next;
    return ptmp;
}
node* ListNode::findLast(node *current){
    if(isEmpty() != true)
    {
        int lastIndex = index(current) - 1;
        ptmp = head;
        for(int i=0; i<lastIndex; i++){
            ptmp = ptmp->next;
        }
    }
    else{
        std::cout<<"listnode is empty "<<std::endl;

    }
    return ptmp;
}

/*
* Insert and append should be separated
* Here to be modified
*/
bool ListNode::insert(int index, int value){
    if(isEmpty() && index==1){
        node *pNew = new node;
        head->next = pNew;
        pNew->value = value;
        pNew->next = nullptr;
        return true;
    }
    if(index > length())
        return false;
    pNext = findNode(index);
    pLast = findLast(pNext);

    node *pnew = new node;
    pnew->next = pNext;
    pLast->next = pnew;
    pnew->value = value;
    return true;
}

bool ListNode::deleteNode(int index){
    if(index > length())
        return false;
    pNext = findNode(index);
    pLast = findLast(pNext);

    node* p = pNext;
    pLast->next = pNext->next;
    delete p;
    p = nullptr;
    return true;
}

/*
* The destructor cannot execute
* Delete repeats only once
*/
ListNode::~ListNode(){
    ptmp = head;
    while (ptmp->next != nullptr) {
        node *rem = new node;
        rem = ptmp;
        ptmp = ptmp->next;
        delete rem; // only once???
        rem = nullptr;
    }
    std::cout<<" disconstructer2 "<<std::endl;
    delete ptmp;
    delete head;
    delete tail;
    delete pLast;
    delete pNext;

}

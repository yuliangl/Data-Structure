#include "listnode.h"
#include <iostream>


ListNode::ListNode(int len)
    :head(new node),
     tail(new node),
     ptmp(nullptr),
     pLast(nullptr),
     pNext(nullptr),
     len(len),
     value(0)
{   tail = head;
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

void ListNode::traverse(node *head){
    ptmp = head;
    while(ptmp->next != nullptr){
        std::cout << ptmp->next->value << std::endl;
        ptmp = ptmp->next;
    }
}

void ListNode::sort(node *head){
    int i, j, tmp;
    int len = length(head);
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

int ListNode::length(node *head){
    int i = 0;
    ptmp = head;
    while(ptmp->next != nullptr){
        i++;
        ptmp = ptmp->next;
    }
    return i;
}

bool ListNode::isEmpty(node *head){
    if(head->next == nullptr)
        return true;
    return false;
}

int ListNode::index(node *head, node *current){
    if(isEmpty(head)){
        std::cout<<"listnode is empty"<<std::endl;
        return 0;
    }
    int index = 0;
    ptmp = head;
    for(int i=0; i<length(head); i++){
        ptmp = ptmp->next;
        if (ptmp == current){
            index = i+1;
            break;
        }
    }
    std::cout<<"index is :"<< index <<std::endl;
    return index;
}
node* ListNode::findNode(node *head,int index){
    if(index>length(head)){
        std::cout<<"index is over length"<<std::endl;
        return 0;
    }
    ptmp = head;
    for(int i=0;i<index; i++)
        ptmp = ptmp->next;
    std::cout<< index << " is " << ptmp->value<<std::endl;
    return ptmp;
}
node* ListNode::findLast(node *head, node *current){
    if(isEmpty(head) != true && length(head)!=1)
    {
        ptmp = head;
        int lastIndex = index(head, current) - 1;
        for(int i=0; i<lastIndex; i++){
            ptmp = ptmp->next;
         std::cout<<"findLast value is " << ptmp->value<<std::endl;
        }
    }
    else
        std::cout<<"listnode is empty or length is 1 "<<std::endl;
        return 0;

    return ptmp;
}

bool ListNode::insert(node *head, int index, int value){
    if(index > length(head))
        return false;
    pNext = findNode(head, index);
    pLast = findLast(head, pNext);

    std::cout<<"pLast value is " << pLast->value<<std::endl;

//    node *pnew = new node;
    ptmp->next = pNext;
    pLast->next = ptmp;
    ptmp->value = value;
    return true;
}

bool ListNode::deleteNode(node *head, int index){
    if(index > length(head))
        return false;
    pNext = findNode(head, index);
    pLast = findLast(head, pNext);

    pLast->next =pNext->next;
    return true;
}

ListNode::~ListNode(){
    delete ptmp;
    delete head;
    delete tail;
    delete pLast;
    delete pNext;
}

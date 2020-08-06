#include "listnode.h"
#include <iostream>


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
//    std::cout<<"head0 is :"<< head <<std::endl;
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
    int leng = length(head);
    int index = 0;
    ptmp = head;// ptmp = head = 0  _??????????????????????????????????????????
//    std::cout<<"head1 is :"<< head <<std::endl;
//    std::cout<<"head1 is :"<< head->next <<std::endl;
//    std::cout<<"head1 is :"<< head->next->next <<std::endl;
//    std::cout<<"head1 is :"<< head->next->next->next <<std::endl;
//    std::cout<<"head1 is :"<< head->next->next->next->next <<std::endl;

//    std::cout<<"ptmp0 is :"<< ptmp <<std::endl;
//    std::cout<<"ptmp0 is :"<< ptmp->next <<std::endl;
//    std::cout<<"ptmp0 is :"<< ptmp->next->next <<std::endl;
//    std::cout<<"ptmp0 is :"<< ptmp->next->next->next <<std::endl;
//    std::cout<<"ptmp0 is :"<< ptmp->next->next->next->next <<std::endl;

    for(int i=0; i<leng; i++){
        ptmp = ptmp->next;
//        std::cout<<"ptmp1 is :"<< ptmp <<std::endl;
//        std::cout<<"index1 is :"<< index <<std::endl;
        if (ptmp == current){
            index = i+1;
//            std::cout<<"index2 is :"<< index <<std::endl;
            break;
        }
    }
//    std::cout<<"index3 is :"<< index <<std::endl;
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
//    std::cout<< index << " is " << ptmp->value<<std::endl;
    return ptmp;
}
node* ListNode::findLast(node *head, node *current){
    if(isEmpty(head) != true && length(head)!=1)
    {

        int lastIndex = index(head, current) - 1;////////////////////////////////error is here
        ptmp = head;
        for(int i=0; i<lastIndex; i++){
            ptmp = ptmp->next;
        }
    }
    else{
        std::cout<<"listnode is empty or length is 1 "<<std::endl;
        return 0;
    }
    return ptmp;
}

bool ListNode::insert(node *head, int index, int value){
    if(index > length(head))
        return false;
    pNext = findNode(head, index);
//    std::cout<<"pNext value is " << pNext <<std::endl;
    pLast = findLast(head, pNext);

//    std::cout<<"pLast value is " << pLast->value<<std::endl;

    node *pnew = new node;
    pnew->next = pNext;
    pLast->next = pnew;
    pnew->value = value;
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

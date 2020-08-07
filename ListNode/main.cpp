#include <iostream>
#include "listnode.h"

using namespace std;

int main()
{
    ListNode *ln = new ListNode(4);
    int len = ln->length();
    cout << "len is : " << len << endl;

    bool b = ln->isEmpty();
    cout << "b is : " << b << endl;

    cout << "traverse is : " <<endl;
    ln->traverse();

    cout << "sort is : " << endl;
    ln->sort();

    cout << "sort traverse is : " << endl;
    ln->traverse();


    ln->insert(3, 30);
    cout << "insert1 traverse is : " <<endl;
    ln->traverse();
    ln->insert(2, 20);
    cout << "insert2 traverse is : " <<endl;
    ln->traverse();
    ln->insert(4, 40);
    ln->insert(6, 60);
    cout << "insert3 traverse is : " <<endl;
    ln->traverse();

    ln->deleteNode(2);
    cout << "deleteNode1 traverse is : " <<endl;
    ln->traverse();
    ln->deleteNode(2);
    cout << "deleteNode2 traverse is : " <<endl;
    ln->traverse();
    ListNode ez;
    ez.traverse();
    ez.insert(1,20);
    ez.insert(1,30);
    ez.insert(1,40);
    ez.insert(1,50);
    ez.traverse();

    ez.insert(1,60);
    ListNode kasa(ez);
    kasa.traverse();


    return 0;
}

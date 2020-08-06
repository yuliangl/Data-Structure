#include <iostream>
#include "listnode.h"

using namespace std;

int main()
{
    ListNode *ln = new ListNode(4);
    int len = ln->length(ln->head);
    cout << "len is : " << len << endl;

    bool b = ln->isEmpty(ln->head);
    cout << "b is : " << b << endl;

    cout << "traverse is : " <<endl;
    ln->traverse(ln->head);

    cout << "sort is : " << b << endl;
    ln->sort(ln->head);

    cout << "sort traverse is : " << b << endl;
    ln->traverse(ln->head);


    ln->insert(ln->head, 3, 30);
    cout << "insert1 traverse is : " <<endl;
    ln->traverse(ln->head);
    ln->insert(ln->head, 2, 20);
    cout << "insert2 traverse is : " <<endl;
    ln->traverse(ln->head);
    ln->insert(ln->head, 4, 40);
    ln->insert(ln->head, 6, 60);
    cout << "insert3 traverse is : " <<endl;
    ln->traverse(ln->head);

    ln->deleteNode(ln->head, 2);
    cout << "deleteNode1 traverse is : " <<endl;
    ln->traverse(ln->head);
    ln->deleteNode(ln->head, 2);
    cout << "deleteNode2 traverse is : " <<endl;
    ln->traverse(ln->head);
    return 0;
}

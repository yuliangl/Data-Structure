#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    queue jin(6);
    jin.enQueue(1);
    jin.enQueue(2);
    jin.enQueue(3);
    jin.enQueue(4);
    jin.enQueue(5);
    jin.isFull();
    jin.traverse();
    cout<<"********************1********************" << endl;

    jin.outQueue();
    jin.outQueue();
    jin.traverse();
    cout<<"********************2********************" << endl;

    queue karisuta(jin);
    karisuta.traverse();
    cout<<"********************3********************" << endl;

    karisuta.outQueue();
    karisuta.outQueue();
    karisuta.outQueue();
    cout << "out value: " << karisuta.outQueueValue() <<endl;
    karisuta.isEmpty();
    cout<<"********************4********************" << endl;

    queue keiru(karisuta);
    keiru.isEmpty();
    keiru.enQueue(5);
    keiru.enQueue(4);
    keiru.enQueue(3);
    keiru.enQueue(2);
    keiru.traverse();
    cout<<"********************5********************" << endl;

    jin = keiru;
    jin.traverse();
    return 0;
}

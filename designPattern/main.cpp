#include <iostream>

#include "factory.h"
#include "singleton.h"

using namespace std;

void testFactory(FruitFactory* f_factory){
    Fruit* fruit=f_factory->product();
    fruit->printn();
}
int main()
{
    AppleFactory* apple = new AppleFactory;
    testFactory(apple);
    delete apple;

    return 0;
}

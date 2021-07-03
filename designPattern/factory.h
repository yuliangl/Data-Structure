#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
using namespace std;

class Fruit{
public:
    Fruit(){
        cout << "Fruit is constructed" << endl;
    }
    virtual void printn(){
        cout << "I'm Fruit" << endl;
    }

    virtual ~Fruit(){
        cout << "Fruit destory" << endl;

    }
private:
};

class Apple: public Fruit{
public:
    Apple(){
        cout << "apple is constructed" << endl;
    }
    void printn(){
        cout << "I'm a apple" << endl;
    }
    ~Apple(){
        cout << "apple destory" << endl;
    }
};

class Pear: public Fruit{
public:
    Pear(){
        cout << "pear is constructed" << endl;
    }
    void printn(){
        cout << "I'm a pear" << endl;
    }
    ~Pear(){
        cout << "pear destory" << endl;
    }
};

class FruitFactory
{
public:
    FruitFactory(){
        cout << "Factory is constructed" << endl;
    }

    virtual Fruit* product() = 0;

    virtual ~FruitFactory(){
        cout << "Factory destory" << endl;
    }

};

class AppleFactory: public FruitFactory{
public:
    AppleFactory(): apple(new Apple){
        cout << "AppleFactory is constructed" << endl;
    }
    Fruit* product(){
        return apple;
    }
    ~AppleFactory(){
        cout << "AppleFactory destory" << endl;
        delete apple;
    }
private:
    Apple* apple;
};

class PearFactory: public FruitFactory{
public:
    PearFactory(): pear(new Pear) {
        cout << "PearFactory is constructed" << endl;
    }
    Fruit* product(){
        return pear;
    }
    ~PearFactory(){
        cout << "PearFactory destory" << endl;
        delete pear;
    }
private:
    Pear* pear;
};

#endif // FACTORY_H

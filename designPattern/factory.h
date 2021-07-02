#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
using namespace std;

class Friut{
public:
    Friut();
    virtual void printn(){
        cout << "I'm friut" << endl;
    }

    virtual ~Friut(){

    }
private:
};

class Apple: public Friut{
public:
    Apple():Friut(){}
    void printn(){
        cout << "I'm a apple" << endl;
    }
};

class Pear: public Friut{
public:
    Pear():Friut(){}
    void printn(){
        cout << "I'm a pear" << endl;
    }
};

class Factory
{
public:
    Factory()
        :friut(new Friut()){}

    virtual Friut* product(){
        return friut;
    }
    virtual ~Factory(){
        delete friut;
    }

private:
Friut* friut;
};

class AppleFactory: public Factory{
public:
    AppleFactory():Factory(){}
    Friut
};

#endif // FACTORY_H

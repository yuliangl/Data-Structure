#ifndef SINGLETON_H
#define SINGLETON_H


class Singleton
{
public:
    static Singleton* GetInstance(){
        return singleton;
    }
private:
    Singleton();
    static Singleton* singleton;
};

Singleton* Singleton::singleton = new Singleton;

#endif // SINGLETON_H

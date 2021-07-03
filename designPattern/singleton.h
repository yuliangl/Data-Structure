#ifndef SINGLETON_H
#define SINGLETON_H


class Singleton
{
public:
    Singleton(const Singleton&) = delete ;
    Singleton(const Singleton&&) = delete ;
    static Singleton* GetInstance(){
        return singleton;
    }
    static Singleton* singleton;
private:
    Singleton();

};


#endif // SINGLETON_H

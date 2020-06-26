#include<iostream>
using namespace std;
class A;
class C;

class A
{
public:
    A()
    {
        cout << "父类A构造..." << endl;   
    }
    ~A()
    {
        cout << "父类A析构..." << endl;
    }
};

class C
{
    public:
    C()
    {
        cout << "C构造..." << endl;
    }
    ~C()
    {
        cout << "C析构..." << endl;
    }
};
class B:public A
{
public:
    C c1;
    B()
    {
        cout << "子类B构造..." << endl;   
    }
    ~B()
    {
        cout << "子类B析构..." << endl;
    }
};


int main()
{
    B b;
    return 0;
}
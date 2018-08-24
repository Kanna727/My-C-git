#include <bits/stdc++.h>
using namespace std;


class A
{
private:
    /* data */
public:
    A();
    void show() {std::cout << "Show of A" << endl;}
    ~A();
};

A::A()
{
    std::cout << "Constructor of A" << endl;
}

A::~A()
{
}


class B
{
private:
    /* data */
public:
    B();
    void show() {std::cout << "Show of B" << endl;}
    void A() {std::cout << "Constructor of A in B" << endl;}
    ~B();
};

B::B()
{
    std::cout << "Constructor of B" << endl;
}

B::~B()
{
}



int main()
{
    A a;
    B b;
    b.show();
    a.show();
    b.A();
    return 0;
}
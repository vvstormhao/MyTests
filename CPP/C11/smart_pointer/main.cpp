#include <iostream>
#include <memory>

using namespace std;
class A
{
public:
    virtual void func1() {printf("A::func1\n");}
    virtual void func2() {printf("A::func2\n");}
    virtual void func3() {printf("A::func3\n");}
    virtual void func4() {printf("A::func4\n");}
};

class C
{
public:
    virtual void func1() {printf("C::func1\n");}    
};

class B:public A
{
public:
    virtual void func1() {printf("B::func1\n");}
    virtual void func2() {printf("B::func2\n");}
    void func3() {printf("B::func3\n");}
    void func4() {printf("B::func4\n");}
};

typedef void (*pFunc)();

int main()
{
    A a;
    
    int size = int(sizeof(a));
    printf("a size is %d\n", size);

    B b;
    size = int(sizeof(b));
    printf("b size is %d\n", size);

    printf("a vptr is 0x%x\n", &a);
    printf("b vptr is 0x%x\n", &b);

    pFunc pfunc = (pFunc)*((int*)*(int*)(&b));
    pfunc();

    return 1;
}
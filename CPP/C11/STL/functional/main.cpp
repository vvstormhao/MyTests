#include <iostream>
#include <functional>


int TestFunc(int n1, int n2, std::function<int(int,int)> f)
{
    return f(n1, n2);
}

int main()
{
    int n = 10, f = 20;

    auto l = [n, &f](int n1, int n2)->int {
        //n = n1 + n2; 编译不通过
        f = n1 + n2;

        return n1 + n2;
    };

    auto l1 = [&](int n1, int n2)->int {
        n = n1 + n2;
        f = n1 + n2;

        return n1 + n2;
    };

    int ret = l(40, 40);
    printf("call l n is %d, f is %d, ret is %d\n", n, f, ret);

    int ret2 = l1(80, 80);
    printf("call l1 n is %d, f is %d, ret is %d\n", n, f, ret);

    int ret3 = TestFunc(100, 200, [](int n1, int n2)->int {return n1 + n2;});
    printf("call TestFunc, ret3 %d\n", ret3);



}
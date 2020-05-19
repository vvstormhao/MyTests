#include <iostream>
#include <thread>


void ThreadFun1(int n) 
{
    printf("Thread1 running\n");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for (auto i = 1; i <= 5; ++i)
    {
        ++n;
    }
    printf("Thread1 Done\n");
}

void ThreadFun2(int &n) 
{
    printf("Thread2 running\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));

    for (auto i = 1; i <= 5; ++i)
    {
        ++n;
    }
    printf("Thread2 Done\n");
}


void ThreadFun3(const int &n) 
{
    printf("Thread3 running\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));

    /*for (auto i = 1; i <= 5; ++i)
    {
        ++n;// 无法编译通过
    }*/
    printf("Thread3 Done\n");
}
int main() 
{
    int n1 = 5;
    int n2 = 5;
    std::thread t1(ThreadFun1, n1);
    std::thread t2(ThreadFun2, std::ref(n2));
    std::thread t3(ThreadFun3, std::cref(n2));
    std::thread t4(std::move(t3));

    //t2.detach();
    t1.join();
    t2.join();
    //t3.join();
    t4.join();

    printf("n1 is %d\n", n1);
    printf("n2 is %d\n", n2);
}
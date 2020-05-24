#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> p1 = std::make_shared<int>(4);
    printf("p1 use_count() %d\n", p1.use_count());

    std::shared_ptr<int> p2 = p1;
    printf("p1 use_count() %d\n", p1.use_count());

    std::shared_ptr<int> p3(p1);
    printf("p1 use_count() %d\n", p1.use_count());

    std::shared_ptr<int> p4(new int(10));
    printf("p4 %d\n", *p4);    

    p3.reset(new int(20));
    printf("p3 %d\n", *p3);   
    printf("p1 use_count() %d\n", p1.use_count()); 


}
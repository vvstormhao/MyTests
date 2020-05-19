#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> i(10);
    std::bitset<8> s("11100011");

    // 按照字符串进行打印
    printf("i to string %s\n", i.to_string().c_str());

    // 按整型打印
    printf("s to unsigned int %lu\n", s.to_ulong());


    printf("i.size() %zu\n", i.size());
    printf("i.any() %d\n", i.any());
    printf("i.none() %d\n", i.none());
    printf("s.count() %zu\n", s.count());

    s.set();
    printf("after s.set() %s\n", s.to_string().c_str());

    s.reset();
    printf("after s.reset() %s\n", s.to_string().c_str());

    s.set(4);
    printf("after s.set(4) %s\n", s.to_string().c_str());

    s.reset(4);
    printf("after s.reset(4) %s\n", s.to_string().c_str());
    
    s.set(4, 5);
    printf("after s.set(4, 5) %s\n", s.to_string().c_str());

    s.flip();
    printf("after s.flip() %s\n", s.to_string().c_str());
}
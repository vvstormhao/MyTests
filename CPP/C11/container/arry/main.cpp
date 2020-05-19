#include <stdio.h>
#include <array>
int main()
{
    std::array<int, 5> a1 = {1, 2, 3, 4, 5};

    // 遍历
    for (auto i : a1)
    {
        printf("%d ", i);
    }
    printf("\n");

   for (auto it = a1.begin(); it != a1.end(); ++it)
   {
       printf("%d ", *it);
   }
   printf("\n");

   auto a2 = a1;
   for (auto it = a2.begin(); it != a2.end(); ++it)
   {
       printf("%d ", *it);
   }
}

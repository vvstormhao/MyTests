#include <stdio.h>
#include <stdlib.h>




void qsort(int *pArry, int nLeft, int nRight)
{
    if (NULL == pArry)
    {
        return;
    }

    if (nLeft >= nRight)
    {
        return;
    }

    int base = pArry[nLeft]; // base number
    printf("base number %d\n", base);
    int left = nLeft;
    int right = nRight;

    while (left < right)
    {
        while (pArry[right] >= base && left < right)
        {
            right--;
        }

        printf("found right value %d ", pArry[right]);

        while (pArry[left] <= base && left < right)
        {
            left++;
        }

        printf("found left value %d ", pArry[right]);

        if (left < right)
        {
            int tmp = pArry[left];
            pArry[left] = pArry[right];
            pArry[right] = tmp;

            printf("after swap :");
            for (int nIndex = 0; nIndex < 10; nIndex++)
            {
                printf("%d ", pArry[nIndex]);
            }
        }
        printf("\n");
    }
    int tmp = pArry[left];
    pArry[left] = base;
    pArry[nLeft] = tmp;

    qsort(pArry, nLeft, left - 1);
    qsort(pArry, left + 1, nRight);

}
int main()
{
    int arry[10] = {3,1,45,6,8,2,77,65,90,10};

    printf("before quick sort:\n");
    for (int nIndex = 0; nIndex < 10; nIndex++)
    {
        printf("%d ", arry[nIndex]);
    }
    printf("\n");
    qsort(arry, 0, 9);

    printf("after quick sort:\n");
    for (int nIndex = 0; nIndex < 10; nIndex++)
    {
        printf("%d ", arry[nIndex]);
    }
    printf("\n");

}

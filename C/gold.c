#include<stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int steal(int a[], int left, int right)
{
    if(right - left == 1)
    {
        return max(a[left], a[right]);
    }
    if(right - left == 0)
    {
        return a[right];
    }
    return max(steal(a, left, right - 2) + a[right], steal(a, left, right - 1));
}

int main(int args, char * argv[])
{
    // int house[10] = {4, 5, 3, 2, 6, 9, 1, 8, 7, 2};
    int house[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int money = steal(house, 0, 9);
    printf("%d\n", money);
    return 0;
}

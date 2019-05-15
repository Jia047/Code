#include<stdio.h>

// 对于用数组 0 下标做根节点的对
// 对于位标 i， 其父节点位标为 （i-1）/2， 左孩子， 2×i+1， 右孩子 2×i+2

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// 构建大顶堆
void build_heap(int a[], int index)
{
    while( a[index] > a[(index - 1) / 2])
    {
        swap(a, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}
// 调整堆
void heapify(int a[], int index, int size)
{
    int left = 2 * index + 1;
    while(left < size)
    {
        if(left + 1 < size && a[left] < a[left + 1])
        {
            left++;
        }
        // 如果父节点大于子节点，则不需要再进行比较
        if(a[index] > a[left])
        {
            break;
        }
        swap(a, index, left);
        index = left;
        left = 2 * index + 1;
    }
}

int main(int args, char * argv[])
{
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    for(int i = 0; i < 10; i ++)
    {
        build_heap(a, i);
    }
    int size = 9;
    swap(a, 0, size);
    while(size > 0)
    {
        heapify(a, 0, size--);
        swap(a, 0, size);
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

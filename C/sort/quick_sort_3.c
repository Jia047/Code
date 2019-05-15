#include <stdio.h>

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void quick_sort(int a[], int left, int right)
{
    if(left >= right)
    {
        return ;
    }
    int less = left;
    int more = right;
    int v = a[left];
    int index = left + 1;
    //
    while(index <= more)
    {
        if(a[index] > v)
        {
            swap(a, index++, more--);
        }
        else if (a[index] < v)
        {
            swap(a, index, less++);
        }
        else
        {
            index++;
        }
    }

    quick_sort(a, left, less - 1);
    quick_sort(a, more + 1, right);
}

int main(int argc, char const *argv[]) {
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    quick_sort(a, 0, 9);

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

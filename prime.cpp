#include <stdio.h>
#include <algorithm>

#define p()                           \
    printf("[");                      \
    for (size_t i = 0; i < size; i++) \
    {                                 \
        if (i == size - 1)            \
        {                             \
            printf("%i", nums[i]);    \
            continue;                 \
        }                             \
        printf("%i, ", nums[i]);      \
    }                                 \
    printf("]\nsize:%zu\n", size);
#define remove(index)                         \
    for (size_t i = index; i < size; i++)     \
    {                                         \
        nums[i] = nums[i+1];                  \
    }                                         \
    /*decrese size*/                          \
    size--;

//may've coppied this but shhh
int binarySearch(int array[], int x, int low, int high)
{

    // Repeat until the pointers low and high meet each other
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

void fill(int *arr, int start, size_t size)
{
    for (int i = start; i < size; i++)
    {
        arr[i-start] = i + 2;
    }
}

const size_t BIG_NUM = 10000;//10,000
int main()
{
    int nums[BIG_NUM - 2];
    fill(nums, 2, BIG_NUM);
    size_t size = BIG_NUM - 2;
    

    size_t n = 0; // index of nums
    bool add = true;
    while (n < size)
    {
        for (size_t i = nums[0]; i < BIG_NUM / 2; i++)
        {
            size_t a = nums[n] * i;
            // printf("(%i)*(%i)=%zu\n",nums[n],i,a);
            int index = binarySearch(nums, a,0,size);
            if (index!=-1) {
                remove(index);
                add=false;
            }
        }
        if (add){n++;}else{add=true;}
    }

    p();

    return 0;
}
//1.271s
//1.242s 1.610
//-O3 .734s
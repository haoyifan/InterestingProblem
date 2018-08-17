#include <stdio.h>

int main()
{
    int arr[5];
    // Assume base address of arr is 2000 and size of integer is 32 bit
    printf("%u %u", arr + 1, &arr + 1);

    return 0;
}



// when add a & before array, it returns the address of the whole array. When you add 1, you add the size of the whole array
// so a quick way to get the size of array is &a + 1 - a

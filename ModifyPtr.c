#include <stdio.h>

int main()
{
        int arr[5];

            // Assume that base address of arr is 2000 and size of integer
            //         // is 32 bit
        arr++;
        printf("%u", arr);

        return 0;

}



// Problem: in C, array name is implemented as constant pointer. No way to change it.

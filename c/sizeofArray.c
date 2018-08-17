# include <stdio.h>
 
void print(int arr[])
{
   int n = sizeof(arr)/sizeof(arr[0]);
   int i;
   for (i = 0; i < n; i++)
      printf("%d ", arr[i]);
}
 
int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
   print(arr);
   return 0;
}

// the printf would be used only once or twice (depending on architecture) because the program is doing sizeof(int*) / sizeof(int)
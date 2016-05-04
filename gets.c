#include <stdio.h>

// what is the potential problem with the following code

int main(){
	char buff[10];

	fgets(buff);

	printf("the buffer is %s\r\n", buff);

	return 0;
}
















// gets() does not check the bound. It would probably generate off by 1
// exception if the entered buffer is too large
// fgets() is safe in this case

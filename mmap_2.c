/*
 * Source: https://burnttoys.blogspot.com/2011/04/how-to-allocate-executable-memory-on.html
 */

#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

typedef unsigned (*asmFunc)(void);

unsigned func(void)
{
	return 123;
}

int main()
{
   // probably needs to be page aligned...

   unsigned int codeBytes = 4096;
   void * virtualCodeAddress = 0;

   virtualCodeAddress = mmap(
       NULL,
       codeBytes,
       PROT_READ | PROT_WRITE | PROT_EXEC,
       MAP_ANONYMOUS | MAP_PRIVATE,
       0,
       0);

   printf("virtualCodeAddress = %p\n", virtualCodeAddress);

   // write some code in
   unsigned char * tempCode = (unsigned char *) (virtualCodeAddress);

   // NOTE: if the copy size is small enough (100 or so), it won't cause
   // segfault. If the copy size is too large (4096, for example), it will crash.
   memcpy(tempCode, &func, 100);

   asmFunc myFunc = (asmFunc) (virtualCodeAddress);

   unsigned out = myFunc();

   printf("out is %d\n", out);

   return 0;
}

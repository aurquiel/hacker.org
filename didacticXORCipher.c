/*Here is a string of bytes encoded in hex:
3d2e212b20226f3c2a2a2b
These bytes have been encrypted with a cunning cipher: each character has been
 XOR'd with 79 (decimal). In cryptography, '79' is referred to as the 'key'.

To decrypt it, perform the same XOR again. This will reveal your answer. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	const char str[] = "3d2e212b20226f3c2a2a2b";

	for(int i=0; i<strlen(str) ; i+=2)
	{
	        char* bytes= (char*)malloc((3)*sizeof(char));
        	strncpy(bytes,str+i,2);
        	int num = (int)strtol(bytes,NULL,16);
        	printf("%c",num^79);
        	free(bytes);
	}

	printf("\n");

	return EXIT_SUCCESS;
}

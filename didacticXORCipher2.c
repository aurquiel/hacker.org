/*Challenge 'Didactic XOR Cipher 2' [Crypto]
Here is a string of bytes encoded in hex:
948881859781c4979186898d90c4c68c85878f85808b8b808881c6c4828b96c4908c8d97c4878c858888818a8381
This sequence has been encrypted with the same cipher as in the previous challenge: each
character has been XOR'd with a certain byte. To decrypt it, perform the same XOR again.
This time, you will have to discover the key yourself*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	const char str[] = "948881859781c4979186898d90c4c68c85878f85808b8b808881c6c4828b96c4908c8d97c4878c858888818a8381";

	for(int i=0; i<strlen(str) ; i+=2)
	{
        	char* bytes= (char*)malloc((3)*sizeof(char));
        	strncpy(bytes,str+i,2);
        	int num = (int)strtol(bytes,NULL,16);
        	printf("%c",num^0xe4);//I just did it with the ascii table and the gonme-calculator mode programmer:)
        	free(bytes);
	}

	printf("\n");

	return EXIT_SUCCESS;
}

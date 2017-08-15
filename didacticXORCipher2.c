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

	for (int key=0; key<256; key ++) //look all the possibilities of combinations 256 1 Byte Key
	{
		char* decrypterStr = (char*)malloc((sizeof(str)/2)+1); //Allocate space to the string decrypter
		int iteratorDecrypter = 0;

		for(int i=0; i<strlen(str) ; i+=2)//Take bytes fron string
		{
			char* bytes= (char*)malloc((3)*sizeof(char));
			strncpy(bytes,str+i,2); //cpy the byte taked to str char array *bytes
			int num = (int)strtol(bytes,NULL,16);  //transfor form char base 16 value to int value

			if ( ((num^key)>31) && ((num^key)<127) )
    			{
				*(decrypterStr + iteratorDecrypter) = (num^key); //wrie to possible answer
				iteratorDecrypter++;
    			}
    			else
    			{
				free(bytes);
				*decrypterStr = '\0';
				break;
    			}

			free(bytes);
		}		

		if (*decrypterStr != '\0')
    			printf("%s   KEY: %d\n", decrypterStr, key);

		free(decrypterStr);
	}

	return EXIT_SUCCESS;
}

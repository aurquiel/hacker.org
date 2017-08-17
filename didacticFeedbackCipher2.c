/*Challenge 'Didactic Feedback Cipher 2' [Crypto]
Here is a string of bytes encoded in hex:
310a7718781f734c31425e775a314f3b40132c5122720599b2dfb790fd8ff894add2a4bdc5d1a6e987a0ed8eee94adcfbb94ee88f382127819623a404d3f
This sequence has been encrypted with a cipher that works as follows:


x = {unknown byte}
k = {unknown byte}
for (i = 0; i < len(txt); i++)
  c = txt[i] ^ k
  print c
  k = (c + x) % 0x100
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char array[] = "310a7718781f734c31425e775a314f3b40132c5122720599b2dfb790fd8ff894add2a4bdc5d1a6e987a0ed8eee94adcfbb94ee88f382127819623a404d3f";

    for (int k = 0; k <256; k++)
    {
        for (int x= 0; x<256; x++)
        {
            char* arrayDecrypted = (char*)malloc(strlen(array)/2+1);
            int writePointer = 0;
            int innerKey = k;

            for (int i = 0; i<strlen(array); i+=2)
            {
                char* byteStr = (char*)malloc(3);
                strncpy(byteStr, array+i, 2);
                int c = strtol(byteStr, NULL, 16);

                if( (c^innerKey)<32 || (c^innerKey)>125 || (c^innerKey)=='#')
                {
                    *arrayDecrypted = '\0';
                    free(byteStr);
                    break;
                }
                else
                {
                    *(arrayDecrypted+writePointer++) = c^innerKey;
                    innerKey = (c+x) % 0x100;
                    free(byteStr);
                }
            }

            if(*(arrayDecrypted)!='\0')
                printf("%s\n",arrayDecrypted);

            free(arrayDecrypted);

        }

    }

    return EXIT_SUCCESS;
}

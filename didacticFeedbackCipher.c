/*Challenge 'Didactic Feedback Cipher' [Crypto]

Here is a string of bytes encoded in hex:
751a6f1d3d5c3241365321016c05620a7e5e34413246660461412e5a2e412c49254a24
This sequence has been encrypted with a cipher
that works as follows:


k = {unknown byte}
for (i = 0; i < len(txt); i++)
  c = txt[i] ^ k
  print c
  k = c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char array[] = "751a6f1d3d5c3241365321016c05620a7e5e34413246660461412e5a2e412c49254a24";

    for (int k = 0; k <256; k++)
    {
        char* arrayDecrypted = (char*)malloc(strlen(array)/2+1);
        int writePointer = 0;
        int innerKey = k;

        for (int i = 0; i<strlen(array); i+=2)
        {
            char* byteStr = (char*)malloc(3);
            strncpy(byteStr, array+i, 2);
            int c = strtol(byteStr, NULL, 16);

            if( (c^innerKey)<32 || (c^innerKey)>125 )
            {
                *arrayDecrypted = '\0';
                free(byteStr);
                break;
            }
            else
            {
                *(arrayDecrypted+writePointer++) = c^innerKey;
                innerKey = c;
                free(byteStr);
            }
        }

        if(*(arrayDecrypted)!='\0')
            printf("%s\n",arrayDecrypted);

        free(arrayDecrypted);

    }

    return EXIT_SUCCESS;
}


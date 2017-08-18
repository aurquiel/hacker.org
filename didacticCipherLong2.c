/*Challenge 'Didactic Feedback Cipher Long 2' [Crypto]

Here is a string of bytes encoded in hex:
5499fa991ee7d8da5df0b78b1cb0c18c10f09fc54bb7fdae7fcb95ace494fbae8f5d90a3c766fdd7b7399eccbf4af592f35c9dc2272be2a45e788697520febd8468c808c2e550ac92b4d28b74c16678933df0bec67a967780ffa0ce344cd2a9a2dc208dc35c26a9d658b0fd70d00648246c90cf828d72a794ea94be51bbc6995478505d37b1a6b8daf7408dbef7d7f9f76471cc6ef1076b46c911aa7e75a7ed389630c8df32b7fcb697c1e89091c30be736a4cbfe27339bb9a2a52a280
This sequence has been encrypted with a cipher that works
 as follows:


k = {unknown 4-byte value}
x = {unknown 4-byte value}
for (i = 0; i < len(txt); i += 4)
  c = (txt[i] -> txt[i + 3]) ^ k
  print c
  k = (c + x) % 0x100000000

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char array[] = "e5534adac53023aaad55518ac42671f8a1471d94d8676ce1b11309c1c27a64b1ae1f4a91c73f2bfce74c5e8e826c27e1f74c4f8081296ff3ee4519968a6570e2aa0709c2c4687eece44a1589903e79ece75117cec73864eebe57119c9e367fefe9530dc1";

    for (unsigned int k = 0; k<4294967295; k++) //
    {
        char* arrayDecrypted = (char*)malloc(strlen(array)+1);
        int writePointer = 0;
        unsigned int innerKey = k;

        for (unsigned int x = 0; x<4294967295; x++)
        {
            for (int i = 0; i<strlen(array); i+=8)
            {
                char* byteStr = (char*)malloc(9);
                strncpy(byteStr, array+i, 8);
                unsigned int c = strtol(byteStr, NULL, 16);

                //We need to split the key and the hex string holded in c variable to represent 4 bytes
                if( ((c&255)^(innerKey&255))<32 || ((c&255)^(innerKey&255))>122 ||
                    (((c>>8)&255)^((innerKey>>8)&255))<32 || (((c>>8)&255)^((innerKey>>8)&255))>122 ||
                    (((c>>16)&255)^((innerKey>>16)&255))<32 || (((c>>16)&255)^((innerKey>>16)&255))>122 ||
                    (((c>>24)&255)^((innerKey>>24)&255))<32 || (((c>>24)&255)^((innerKey>>24)&255))>122 ||
                    (((c&255)^(innerKey&255))<38 && ((c&255)^(innerKey&255))>34) ||
                    ((((c>>8)&255)^((innerKey>>8)&255))<38 && (((c>>8)&255)^((innerKey>>8)&255))>34) ||
                    ((((c>>16)&255)^((innerKey>>16)&255))<38 && (((c>>16)&255)^((innerKey>>16)&255))>34) ||
                    ((((c>>24)&255)^((innerKey>>24)&255))<38 && (((c>>24)&255)^((innerKey>>24)&255))>34) )
                {
                    *arrayDecrypted = '\0';
                    free(byteStr);
                    break;
                }
                else
                {
                    *(arrayDecrypted+writePointer++) = (((c>>24)&255)^((innerKey>>24)&255));
                    *(arrayDecrypted+writePointer++) = (((c>>16)&255)^((innerKey>>16)&255));
                    *(arrayDecrypted+writePointer++) = (((c>>8)&255)^((innerKey>>8)&255));
                    *(arrayDecrypted+writePointer++) = (c&255)^(innerKey&255);
                    innerKey = (c + x) % 0x100000000;
                    free(byteStr);
                }
            }

            if(*(arrayDecrypted)!='\0')
            {
                printf("%s KEY:%u\n",arrayDecrypted, k);
                abort(); //There are too many possibilities just finish with the first one
            }

        }

        free(arrayDecrypted);

    }

    return EXIT_SUCCESS;
}

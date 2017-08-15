/*Challenge 'Didactic Red' [Crypto]
Here we see another image, a four-pixel wide and single pixel high line:

Unlike the previous challenge, the only color here is red. Therefore,
it's probably a good start to assume that the signal (the information
we're trying to extract from the source) is just the red component,
which means 8 bits per pixel. To answer this challenge, submit these
four red values concatenated together, expressed in hexadecimal. Ie:
something like '92AB7DF2'. A hint: the answer is based on an English
word. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void)
{
    int redValues[4] ={0xde0000,0xfa0000, 0xce0000, 0xd10000}; //I use GIMP to know the Hex code of colors

    for (uint64_t i=0, result = 0; i<4; i++)
    {
        printf("%llx \n",(unsigned long long)(result = (result<<(8))|redValues[i]));
    }

    return EXIT_SUCCESS;
}

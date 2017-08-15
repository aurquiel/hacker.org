/*Challenge 'Didactic Bytes' [Crypto]

Let us take the following three decimal numbers:
199, 77, 202
Convert each one into a byte. (Even though 77 does
not require all 8 bits to express itself, when
dealing with a group of data, we usually keep it in
a consistent form.) Now, take those three bytes and
combine them to form a 24-bit unsigned integer.
The 199 byte is the high byte (most significant) and
so forth. Please enter that 24-bit integer in decimal
form, and that is your answer. (Hint: your answer will
 not be '19977202'!) */

#include <stdio.h>
#include <stdlib.h>

void combinedFunction (int);

int a = 199, b = 77, c= 202;
int combined;

int main()
{
    combinedFunction(a);
    combinedFunction(b);
    combinedFunction(c);

    printf("%d\n",combined);
    return 0;
}

void combinedFunction (int x)
{
    combined=((combined<<8)|x);
}

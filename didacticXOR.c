/*Challenge 'Didactic XOR' [Crypto]
Let's take the following byte, expressed in hexadecimal:
9f
Please XOR this with the following byte:
c7
Now, what is the ASCII character of the result?  */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	printf("%c \n",0x9f^0xc7);
	return EXIT_SUCCESS;
}

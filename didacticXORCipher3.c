/*Challenge 'Didactic XOR Cipher 3' [Crypto]
Here is a string of bytes encoded in hex:
31cf55aa0c91fb6fcb33f34793fe00c72ebc4c88fd57dc6ba71e71b759d83588
This sequence has been encrypted with a cipher that works as follows. The first byte has been XOR'd with a byte we'll call 'b'. There is a another component to the key, a byte we'll call 'x'. Each time a byte gets XOR'd by b, the following change is executed:
b = (b + x) % 256
In other words, the cipher byte changes with each character encrypted. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
const char* string = "31cf55aa0c91fb6fcb33f34793fe00c72ebc4c88fd57dc6ba71e71b759d83588";

char* myByte = (char*)malloc(3); //allocate memory for the bye to read.

for(int b=0; b<256; b++)
{
for(int x=0; x<256; x++)
{

  int bTest = b; //saving the value of b for not chaging inside the other for cicle :)
  char* myTestResult = (char*)malloc(strlen(string));
  char flag = 0;
  
  for(int i=0; i<strlen(string); i+=2)
  {

    strncpy(myByte,string+i,2);

    //Tranform to hex number
    char *end;
    unsigned long int number = strtoul(myByte,&end,16);

    if ( (bTest^number)<32 || (bTest^number)>122 )
    {
      flag = 1;
      free(myTestResult);
      break;
    }
    else
    {
      *(myTestResult+strlen(myTestResult)) = bTest^number;
      *(myTestResult+strlen(myTestResult)+1) = '\0';
    }

    bTest = (bTest + x) % 256;

  } //End of myByte

  if (!flag)
  {
    printf("%s\n",myTestResult);
    free(myTestResult);
  }
  else
  {
    flag = 0;
  }

} //End of x 

} //End of b

free(myByte); //Free memory allocation

return 0;
}





  

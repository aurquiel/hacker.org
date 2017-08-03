//I CAN'T SOLVED IT

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
    
      for(int i=0; i<strlen(string); i+=2)
      {
      
	strncpy(myByte,string+i,2);

	//Tranform to hex number
	char *end;
	unsigned long int number = strtoul(myByte,&end,16);

	if ( ( (bTest^number)<64 && ( (bTest^number)!=32)  ) || (bTest^number)>122 )
	  break;

	printf  ("%c",(char)(bTest^number));
	
	bTest = (bTest + x) % 256;
	
      } //End of myByte
      
    } //End of x 

  } //End of b

  free(myByte); //Free memory allocation
    
  return 0;
}





  

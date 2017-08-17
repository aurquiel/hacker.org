/*Challenge 'Broken XOR 3' [Crypto]
Here is a string of bytes encoded in hex:
8d541ae26426f8b97426b7ae7240d78e401f8f904717d09b2fa4a4622cfcbf7337fbba2cdbcb4e3cdb994812b66a27e9e02f21faf8712bd2907fc384564998857e3b1
This sequence has been encrypted with the same
cipher as the Didactic XOR 3 challenge. However,
the creator of this cipher had a bug in his code:
any byte he printed in hex, if it started with a
0 he forgot to print it. I.e., if a byte was:
0d
It would be printed in the above string as:
d */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    /*i just were adding bytes to the string to got an output when i dinn't have an output it was due to the missing 0, for annother part the string is corrupted.*/
    const char* string = "8d541ae26426f8b97426b7ae7240d78e401f8f904717d09b2fa4a4622cfcbf7337fbba020cdbcb4e3cdb994812b66a27e9e02f21faf8712bd290070f";
                                                                                        //      0 0                                           0 0
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

                if (( (bTest^number)<32 || (bTest^number)>125 ) )
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
                printf("%s KEYS: b=%d x=%d\n",myTestResult,b,x);
                free(myTestResult);
            }
            else
            {
                flag = 0;
            }

        } //End of x

    } //End of b

    free(myByte); //Free memory allocation

    return EXIT_SUCCESS;
}

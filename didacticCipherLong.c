/*Challenge 'Didactic Feedback Cipher Long' [Crypto]

Here is a string of bytes encoded in hex:
e5534adac53023aaad55518ac42671f8a1471d94d8676ce1b11309c1c27a64b1ae1f4a91c73f2bfce74c5e8e826c27e1f74c4f8081296ff3ee4519968a6570e2aa0709c2c4687eece44a1589903e79ece75117cec73864eebe57119c9e367fefe9530dc1
This sequence has been encrypted with a cipher that works as follows:


k = {unknown 4-byte value}
for (i = 0; i < len(txt); i += 4)
  c = (txt[i] -> txt[i + 3]) ^ k
  print c
  k = c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct to hold the words of the dictionary
typedef struct listWordStruct{
    char* word;
}listWord;

listWord myListWord[] = {
    {"aboard"},
    {"answer"},
    {"about"},
    {"above"},
    {"across"},
    {"after"},
    {"against"},
    {"along"},
    {"amid"},
    {"among"},
    {"anti"},
    {"around"},
    {"before"},
    {"behind"},
    {"below"},
    {"beneath"},
    {"beside"},
    {"besides"},
    {"between"},
    {"beyond"},
    {"but"},
    {"concerning"},
    {"considering"},
    {"despite"},
    {"down"},
    {"during"},
    {"except"},
    {"excepting"},
    {"excluding"},
    {"following"},
    {"for"},
    {"from"},
    {"inside"},
    {"into"},
    {"like"},
    {"minus"},
    {"near"},
    {"onto"},
    {"opposite"},
    {"outside"},
    {"over"},
    {"past"},
    {"per"},
    {"plus"},
    {"regarding"},
    {"round"},
    {"save"},
    {"since"},
    {"than"},
    {"through"},
    {"toward"},
    {"towards"},
    {"under"},
    {"underneath"},
    {"unlike"},
    {"until"},
    {"upon"},
    {"versus"},
    {"via"},
    {"with"},
    {"within"},
    {"without"},
    {"this"},
    {"summit"}
};

//Number of structs in the array
#define SIZEMYLISTWORD sizeof(myListWord)/sizeof(myListWord[0])

//Function to look for matches in the dictionaty
int filterResult(char* s, listWord* myListWord);

int main(void)
{
    const char array[] = "e5534adac53023aaad55518ac42671f8a1471d94d8676ce1b11309c1c27a64b1ae1f4a91c73f2bfce74c5e8e826c27e1f74c4f8081296ff3ee4519968a6570e2aa0709c2c4687eece44a1589903e79ece75117cec73864eebe57119c9e367fefe9530dc1";

    for (int k = 0; k <4294967295; k++)
    {
        char* arrayDecrypted = (char*)malloc(strlen(array)+1);
        int writePointer = 0;
        int innerKey = k;

        for (int i = 0; i<strlen(array); i+=8)
        {
            char* byteStr = (char*)malloc(9);
            strncpy(byteStr, array+i, 8);
            int c = strtol(byteStr, NULL, 16);

            //We need to split the key and the hex string holded in c variable to represent 4 bytes
            if( ((c&255)^(innerKey&255))<32 || ((c&255)^(innerKey&255))>126 ||
                (((c>>8)&255)^((innerKey>>8)&255))<32 || (((c>>8)&255)^((innerKey>>8)&255))>126 ||
                (((c>>16)&255)^((innerKey>>16)&255))<32 || (((c>>16)&255)^((innerKey>>16)&255))>126 ||
                (((c>>24)&255)^((innerKey>>24)&255))<32 || (((c>>24)&255)^((innerKey>>24)&255))>126 )
            {
                *arrayDecrypted = '\0';
                free(byteStr);
                break;
            }
            else
            {
                *(arrayDecrypted+writePointer++) = (c&255)^(innerKey&255);
                *(arrayDecrypted+writePointer++) = (((c>>8)&255)^((innerKey>>8)&255));
                *(arrayDecrypted+writePointer++) = (((c>>16)&255)^((innerKey>>16)&255));
                *(arrayDecrypted+writePointer++) = (((c>>24)&255)^((innerKey>>24)&255));
                innerKey = c;
                free(byteStr);
            }
        }

        if(*(arrayDecrypted)!='\0' && filterResult(arrayDecrypted, myListWord))
            printf("%s\n",arrayDecrypted);

        free(arrayDecrypted);

    }

    return EXIT_SUCCESS;
}

int filterResult(char* s, listWord* p_myListWord)
{
    char* pointerWord;

    for (int i=0; i<SIZEMYLISTWORD; i++)
    {
        if( (pointerWord = strstr(s, (p_myListWord+i)->word)) )
        {
            if (*(pointerWord + strlen((p_myListWord+i)->word)) == ' ')
            {
                printf("Dictionary word founded: %s\n",(p_myListWord+i)->word);
                return 1;
            }
        }
    }

    return 0;
}


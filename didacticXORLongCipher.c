/*Challenge 'Didactic XOR Long Cipher' [Crypto]
Here is a string of bytes encoded in hex:
8776459cf37d459fbb7b5ecfbb7f5fcfb23e478aaa3e4389f378439aa13e4e96a77b5fc1f358439df36a4486a03e4381b63e5580a66c0c8ebd6d5b8aa13e459cf34e4d9fa67f02cf90714288a17f589abf7f5886bc705fcfbc700c96bc6b5ecfb7775f8cbc68499daa3f
This sequence has been encrypted with the same
cipher as in Didactic XOR 2, except here the key
is four-bytes long. So the first byte of the
plaintext is enciphered with the first byte of the
key, and so on, until the fifth byte of the plaintext
gets enciphered with the first byte of the key again. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//implement a dictionary
typedef struct listWordStruct{
    char* word;
} listWord;

listWord myListWord[]={
    {"a"},
    {"aboard"},
    {"about"},
    {"above"},
    {"across"},
    {"after"},
    {"against"},
    {"along"},
    {"amid"},
    {"among"},
    {"an"},
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
    {"by"},
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
    {"in"},
    {"inside"},
    {"into"},
    {"like"},
    {"minus"},
    {"near"},
    {"off"},
    {"on"},
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
    {"to"},
    {"toward"},
    {"towards"},
    {"under"},
    {"underneath"},
    {"unlike"},
    {"until"},
    {"up"},
    {"upon"},
    {"versus"},
    {"via"},
    {"with"},
    {"within"},
    {"without"},
    {"the"},
{"this"}
};

#define NUMBER_OF_ELEMENTS sizeof(myListWord)/sizeof(myListWord[0])

char* decrypt(int keyA, int keyB, int keyC, int keyD, const char* s);
int lookDictionary(char *s, listWord* p_myListWord);

int main(void)
{
    const char array[]="8776459cf37d459fbb7b5ecfbb7f5fcfb23e478aaa3e4389f378439aa13e4e96a77b5fc1f358439df36a4486a03e4381b63e5580a66c0c8ebd6d5b8aa13e459cf34e4d9fa67f02cf90714288a17f589abf7f5886bc705fcfbc700c96bc6b5ecfb7775f8cbc68499daa3f";

    char* firstBitsArray = (char*)malloc((strlen(array)/4)+2);
    char* secondBitsArray = (char*)malloc((strlen(array)/4)+2);
    char* thirdBitsArray = (char*)malloc((strlen(array)/4)+1);
    char* fourthBitsArray = (char*)malloc((strlen(array)/4)+1);

    //Fill the arrays
    for(int i=0; i< strlen(array); i+=8)
    {
        strncat((firstBitsArray+(i/4)), (array+i), 2);
        strncat((secondBitsArray+(i/4)), (array+i+2), 2);
        strncat((thirdBitsArray+(i/4)), (array+i+4), 2);
        strncat((fourthBitsArray+(i/4)), (array+i+6), 2);
    }

    printf("Possile keys:\n");

    char* firstBitsArrayDecrypter = (char*)malloc((strlen(array)/4)+1);
    int* arrayKeyA = (int*)malloc(sizeof(int));
    int sizeArrayKeyA = 0;
    //Find key A
    for (int keyA=0; keyA<256; keyA++)
    {
        char* byteStr = (char*)malloc(2+1);
        int writeCounter = 0;

        for (int j=0; j<strlen(firstBitsArray); j+=2)
        {
            strncpy(byteStr, (firstBitsArray+j),2);

            int byteNum = strtol(byteStr, NULL, 16);

            if ( ((byteNum^keyA)<32 || (byteNum^keyA)>122 ) || ((byteNum^keyA)>32 && (byteNum^keyA)<=38) )
            {
                *(firstBitsArrayDecrypter) = '\0';
                break;
            }
            else
            {
                *(firstBitsArrayDecrypter+writeCounter++) = byteNum^keyA;
            }
        }

        if ( *(firstBitsArrayDecrypter)!='\0')
        {
            printf("%s Key%c: %d\n", firstBitsArrayDecrypter, 'A', keyA);
            *(arrayKeyA+sizeArrayKeyA) = keyA;
            sizeArrayKeyA++;
            arrayKeyA = (int*)realloc((int*)arrayKeyA, sizeof(int)*(sizeArrayKeyA+1));
        }
    }

    char* secondBitsArrayDecrypter = (char*)malloc((strlen(array)/4)+1);
    int* arrayKeyB = (int*)malloc(sizeof(int));
    int sizeArrayKeyB = 0;
    //Find key B
    for (int keyB=0; keyB<256; keyB++)
    {
        char* byteStr = (char*)malloc(2+1);
        int writeCounter = 0;

        for (int j=0; j<strlen(secondBitsArray); j+=2)
        {
            strncpy(byteStr, (secondBitsArray+j),2);

            int byteNum = strtol(byteStr, NULL, 16);

            if ( ((byteNum^keyB)<32 || (byteNum^keyB)>122 ) || ((byteNum^keyB)>34 && (byteNum^keyB)<=38) )
            {
                *(secondBitsArrayDecrypter) = '\0';
                break;
            }
            else
            {
                *(secondBitsArrayDecrypter+writeCounter++) = byteNum^keyB;
            }
        }

        if ( *(secondBitsArrayDecrypter)!='\0')
        {
            printf("%s Key%c: %d\n", secondBitsArrayDecrypter, 'B', keyB);
            *(arrayKeyB+sizeArrayKeyB) = keyB;
            sizeArrayKeyB++;
            arrayKeyB = (int*)realloc((int*)arrayKeyB, sizeof(int)*(sizeArrayKeyB+1));
        }
    }

    char* thirdBitsArrayDecrypter = (char*)malloc((strlen(array)/4)+1);
    int* arrayKeyC = (int*)malloc(sizeof(int));
    int sizeArrayKeyC = 0;
    //Find key C
    for (int keyC=0; keyC<256; keyC++)
    {
        char* byteStr = (char*)malloc(2+1);
        int writeCounter = 0;

        for (int j=0; j<strlen(thirdBitsArray); j+=2)
        {
            strncpy(byteStr, (thirdBitsArray+j),2);

            int byteNum = strtol(byteStr, NULL, 16);

            if ( ((byteNum^keyC)<32 || (byteNum^keyC)>122 ) || ((byteNum^keyC)>32 && (byteNum^keyC)<=38) )
            {
                *(thirdBitsArrayDecrypter) = '\0';
                break;
            }
            else
            {
                *(thirdBitsArrayDecrypter+writeCounter++) = byteNum^keyC;
            }
        }

        if ( *(thirdBitsArrayDecrypter)!='\0')
        {
            printf("%s Key%c: %d\n", thirdBitsArrayDecrypter, 'C', keyC);
            *(arrayKeyC+sizeArrayKeyC) = keyC;
            sizeArrayKeyC++;
            arrayKeyC = (int*)realloc((int*)arrayKeyC, sizeof(int)*(sizeArrayKeyC+1));
        }
    }

    char* fourthBitsArrayDecrypter = (char*)malloc((strlen(array)/4)+1);
    int* arrayKeyD = (int*)malloc(sizeof(int));
    int sizeArrayKeyD = 0;
    //Find key D
    for (int keyD=0; keyD<256; keyD++)
    {
        char* byteStr = (char*)malloc(2+1);
        int writeCounter = 0;

        for (int j=0; j<strlen(fourthBitsArray); j+=2)
        {
            strncpy(byteStr, (fourthBitsArray+j),2);

            int byteNum = strtol(byteStr, NULL, 16);

            if ( ((byteNum^keyD)<32 || (byteNum^keyD)>122 ) || ((byteNum^keyD)>32 && (byteNum^keyD)<=38) )
            {
                *(fourthBitsArrayDecrypter) = '\0';
                break;
            }
            else
            {
                *(fourthBitsArrayDecrypter+writeCounter++) = byteNum^keyD;
            }
        }

        if ( *(fourthBitsArrayDecrypter)!='\0')
        {
            printf("%s Key%c: %d\n", fourthBitsArrayDecrypter, 'D', keyD);
            *(arrayKeyD+sizeArrayKeyD) = keyD;
            sizeArrayKeyD++;
            arrayKeyD = (int*)realloc((int*)arrayKeyD, sizeof(int)*(sizeArrayKeyD+1));
        }
    }

    //Decoded steps

    for (int i = 0; i < sizeArrayKeyA; i++)
        for (int j = 0; j < sizeArrayKeyB; j++)
            for (int k = 0; k < sizeArrayKeyC; k++)
                for (int l = 0; l < sizeArrayKeyD; l++)
                {
                    char* possibleResult = strdup(decrypt(arrayKeyA[i],arrayKeyB[j],arrayKeyC[k],arrayKeyD[l], array));
                    if (lookDictionary(possibleResult, myListWord))
                        printf("%s\n",possibleResult);
                }

    return EXIT_SUCCESS;
}

char* decrypt(int keyA, int keyB, int keyC, int keyD, const char* s)
{
    char* arrayDecrypted = (char*)malloc((strlen(s)/2)+300);
    char* byteStr = (char*)malloc(2+1);
    int byteNum = 0;
    for(int i = 0, p = 0; i<strlen(s); i+=8)
    {
        strncpy(byteStr, (s+i),2);
        byteNum = strtol(byteStr, NULL, 16);
        *(arrayDecrypted+ p++) = byteNum^keyA;

        strncpy(byteStr, (s+i+2),2);
        byteNum = strtol(byteStr, NULL, 16);
        *(arrayDecrypted+ p++) = byteNum^keyB;

        strncpy(byteStr, (s+i+4),2);
        byteNum = strtol(byteStr, NULL, 16);
        *(arrayDecrypted+ p++) = byteNum^keyC;

        strncpy(byteStr, (s+i+6),2);
        byteNum = strtol(byteStr, NULL, 16);
        *(arrayDecrypted+ p++) = byteNum^keyD;
    }

    char strKeyA[4],strKeyB[4],strKeyC[4],strKeyD[4];

    sprintf(strKeyA, "%d", keyA);
    sprintf(strKeyB, "%d", keyB);
    sprintf(strKeyC, "%d", keyC);
    sprintf(strKeyD, "%d", keyD);

    strcat(arrayDecrypted, " THE KEYS ARE, KeyA:");
    strcat(arrayDecrypted, strKeyA);
    strcat(arrayDecrypted, " KeyB:");
    strcat(arrayDecrypted, strKeyB);
    strcat(arrayDecrypted, " KeyC:");
    strcat(arrayDecrypted, strKeyC);
    strcat(arrayDecrypted, " KeyD:");
    strcat(arrayDecrypted, strKeyD);

    free(byteStr);

    return arrayDecrypted;
}

int lookDictionary(char *s, listWord* p_myListWord)
{

    char* pointerWord;

    for (int i=0; i<NUMBER_OF_ELEMENTS; i++)
    {
        if( (pointerWord = strstr(s, (p_myListWord+i)->word)) )
        {
            if (*(pointerWord + strlen((p_myListWord+i)->word)) == ' ')
            {
                printf("Dictionary word founded was: %s\nIn this sentences:\n",(p_myListWord+i)->word);
                return 1;
            }
        }
    }

    return 0;
}


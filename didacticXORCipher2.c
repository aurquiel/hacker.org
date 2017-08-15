/*Challenge 'Didactic XOR Cipher 2' [Crypto]
Here is a string of bytes encoded in hex:
948881859781c4979186898d90c4c68c85878f85808b8b808881c6c4828b96c4908c8d97c4878c858888818a8381
This sequence has been encrypted with the same cipher as in the previous challenge: each
character has been XOR'd with a certain byte. To decrypt it, perform the same XOR again.
This time, you will have to discover the key yourself*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct to hold the words of the dictionary
typedef struct listWordStruct{
    char* word;
}listWord;

listWord myListWord[] = {
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
    {"as"},
    {"at"},
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
    {"of"},
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

//Number of structs in the array
#define SIZEMYLISTWORD sizeof(myListWord)/sizeof(myListWord[0])

//Function to look for matches in the dictionaty
int filterResult(char* s, listWord* myListWord);

int main(int argc, char* argv[])
{

	const char str[] = "948881859781c4979186898d90c4c68c85878f85808b8b808881c6c4828b96c4908c8d97c4878c858888818a8381";

	for (int key=0; key<256; key ++) //look all the possibilities of combinations 256 1 Byte Key
	{
		char* decrypterStr = (char*)malloc((sizeof(str)/2)+1); //Allocate space to the string decrypter
		int iteratorDecrypter = 0;

		for(int i=0; i<strlen(str) ; i+=2)//Take bytes fron string
		{
			char* bytes= (char*)malloc((3)*sizeof(char));
			strncpy(bytes,str+i,2); //cpy the byte taked to str char array *bytes
			int num = (int)strtol(bytes,NULL,16);  //transfor form char base 16 value to int value

			if ( ((num^key)>31) && ((num^key)<127) )
    			{
				*(decrypterStr + iteratorDecrypter) = (num^key); //wrie to possible answer
				iteratorDecrypter++;
    			}
    			else
    			{
				free(bytes);
				*decrypterStr = '\0';
				break;
    			}

			free(bytes);
		}

		if (*decrypterStr != '\0' && filterResult(decrypterStr, myListWord))
		{
            		printf("%s KEY: %d\n",decrypterStr, key);
		}


		free(decrypterStr);
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

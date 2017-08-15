/*Challenge 'Didactic Bits' [Crypto]
Let's look at the following string:


abbbabaaabbabaaaabbaababaabaaaaaabbaaaababbabbbaabbbaabbabbbabbbabbaabababbbaabaaabaaaaaabbabaababbbaabbaabaaaaaabbaaaababbaabaaabbbabababbabbababbaaabaabbbaabaabbaaaababbbabaaabbaabab


Where to get started? The first thing
to notice is that there are only two
kinds of letters in the string.
That should give you a clue as to how
much signal each one represents. Now,
what to do with the series? First, count
how many letters there are. That number
should give you a hint (try factoring it).
Next, try to represent the data in a form
that makes sense. The answer should become
 clear if you take the right approach.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replacement(char *p);

int main()
{
    char const string[]="abbbabaaabbabaaaabbaababaabaaaaaabbaaaababbabbbaabbbaabbabbbabbbabbaabababbbaabaaabaaaaaabbabaababbbaabbaabaaaaaabbaaaababbaabaaabbbabababbabbababbaaabaabbbaabaabbaaaababbbabaaabbaabab";

    //len equals to 184 the highest number resulting in a round division is 8.

    char* result = (char*)malloc((((int)strlen(string)/8)+1)); //aloccate size for the result

    for (int i=0; i<(int)strlen(string); i+=8)
    {
        char* eightBits = (char*)malloc(9); //aloccate size
        strncpy(eightBits,(string+i),8); //we geot 1 byte
        replacement(eightBits); //transfor two bnary
        int numberResult = strtol(eightBits , NULL, 2); //transform to int value

        *(result+i/8)=numberResult; //writting the result

        free(eightBits);
    }

    printf("%s\n", result);
    free(result);

    return 0;
}

void replacement(char *p)
{
    char* savingTransform = (char*)malloc((strlen(p)+1));
    for (char* t=savingTransform, *p2=p; *p2!='\0';t++,p2++)
    {
        if(*p2=='a')
            *t='0';
        else
            *t='1';
    }
    strcpy(p,savingTransform);
    free(savingTransform);
}

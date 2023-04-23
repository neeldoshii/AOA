/* ----------------------------------------- Neel Doshi ----------------------------------------- */
#include <stdio.h>
#include <conio.h>
#include <string.h>

void naiveString(char *text, char *pattern)
{
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int i, j;
    for (i = 0; i < textLen - patternLen; i++)
    {
        for (j = 0; j < patternLen; j++)
        {
            if (text[i + j] != text[j])
            {
                break;
            }
        }
        // if the above for loop ran fully then you can assume it is fully matched
        if (j == patternLen)
        {
            printf("Match found at : %d \n", i);
        }
    }
}

int main()
{
    // the string you want
    char text[] = "AABAACAADAABAAABAA";
    // the pattern it should match
    char pattern[] = "AABA";

    naiveString(text, pattern);
}
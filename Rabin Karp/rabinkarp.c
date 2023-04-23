/* ----------------------------------------- Neel Doshi ----------------------------------------- */

#include <stdio.h>
#include <string.h>
#define d 256

void search(char *text, char *pattern, int q)
{
    int textlen = strlen(text);       // length of text
    int patternlen = strlen(pattern); // length of pattern
    int p = 0;                        // hash value for pattern
    int t = 0;                        // hash value for txt
    int h = 1;

    // calculate h as d^(m-1)
    for (int i = 0; i < patternlen - 1; i++)
    {
        h = (h * d) % q;
    }

    // hash value of pattern at first window
    for (int i = 0; i < patternlen; i++)
    {
        // hash value = no of characters at input * pattern hasvalue + pattern index) mod prime no will give unique hash value
        p = (d * p + pattern[i]) % q;

        // same for text hash value
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i < textlen - patternlen; i++)
    {
        if (p == t)
        {
            for (int j = 0; j < patternlen; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }

                if (j == patternlen - 1)
                {
                    printf("Pattern found at index %d \n", i);
                }
            }
        }

        // When calculating for next window
        //  we delete the leading hash value and add the next tail hash value
        if (i < textlen - patternlen)
        {
            t = (d * (t - text[i] * h) + text[i + patternlen]) % q;
            // if its in negative
            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
}

int main()
{

    // given input text
    char *text = "AAABAADAA";
    // given pattern to find from the input text
    char *pattern = "AAD";
    // prime no for rolling hash function
    int q = 101;
    // calling a function
    search(text, pattern, q);
}
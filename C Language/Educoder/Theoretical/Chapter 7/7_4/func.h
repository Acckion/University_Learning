#include <stdio.h>

void strnCpy(char t[], char s[], int n)
{
    int i = 0;
    while (s[i] != '\0' && i < n)
    {
        t[i] = s[i];
        i++;
    }
    t[i] = '\0';
}

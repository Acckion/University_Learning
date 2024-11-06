#include <stdio.h>
int main()
{
    int ch;
    while ((ch = getchar()) != EOF)
    {
        unsigned char p = '\0';
        p |= (ch & 0x01) << 1;
        p |= (ch & 0x02) >> 1;
        p |= (ch & 0x04) << 1;
        p |= (ch & 0x08) >> 1;
        p |= (ch & 0x10) << 1;
        p |= (ch & 0x20) >> 1;
        char q;
        q = ch >> 6;
        ch = p | (ch & 0xc0);
        int i = 0;
        while (i < q)
        {
            char w = (ch >> 5) & 0x01;
            unsigned char c = 0xc0;
            if (!w)
                ch = ((ch << 1) & 0x3f) | (ch & c);
            else
                ch = ((ch << 1) & 0x3f) | ((ch & c) + 1);
            i++;
        }
        putchar(ch);
    }
    return 0;
}
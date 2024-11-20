#include<stdio.h>
static int countLetters[26] = {};
static int countNumbers[10] = {};
int countOthers = 0;

int contLetter(char c[]) {
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] >= 'a' && c[i] <= 'z') {
            countLetters[c[i] - 'a']++;
        }
    }

    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] >= 'A' && c[i] <= 'Z') {
            countLetters[c[i] - 'A']++;
        }
    }
}

int contNumber(char c[]) {
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] >= '0' && c[i] <= '9') {
            countNumbers[c[i] - '0']++;
        }
    }
}

int countOther(char c[]) {
    for (int i = 0; c[i] != '\0'; i++)
    {
        if ((c[i] < '0' || c[i] > '9') && (c[i] < 'a' || c[i] > 'z') && (c[i] < 'A' || c[i] > 'Z')) {
            countOthers++;
        }
    }
}

int main() {
    char c[100];
    fgets(c, sizeof(c), stdin);
    contLetter(c);
    contNumber(c);
    countOther(c);

    for (int i = 0; i < 10; i++)
    {
        if (countNumbers[i] != 0)
        {
            printf("%c:%d\n", i + '0', countNumbers[i]);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (countLetters[i] != 0) {
            printf("%c:%d\n", i + 'A', countLetters[i]);
        }
    }
    
    if (countOthers != 0) {
        printf("other:%d\n", countOthers-1);
    }
}
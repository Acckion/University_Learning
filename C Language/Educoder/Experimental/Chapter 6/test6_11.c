#include <stdio.h>
#include <string.h>

int main(void) {
    char int1[200], int2[200], new[40000];
    memset(new, '0', sizeof(new));

    fgets(int1, 200, stdin);
    fgets(int2, 200, stdin);
    int1[strcspn(int1, "\n")] = '\0';
    int2[strcspn(int2, "\n")] = '\0';

    int len1 = strlen(int1);
    int len2 = strlen(int2);

    int temp2 = 0;

    for (int i = 0; i < len1; i++) {
        int temp1 = 0;
        int temp3 = 0;
        for (int j = 0; j < len2; j++) {
            temp2 = (((int1[len1 - i-1] - '0') * (int2[len2 - j-1] - '0') + temp1) % 10);
            temp1 = ((int1[len1 - i-1] - '0') * (int2[len2 - j-1] - '0') + temp1) / 10;
            int sum = (new[i + j + 1] - '0') + temp2 + temp3;
            new[i + j + 1] = (sum % 10) + '0';
            temp3 = sum / 10;
        }
        new[i + len2] += temp1 + temp3;
    }

    int start = 0;
    while (start < len1 + len2 && new[start] == '0')
    {
        start++;
    }

    for (int i = start; i < len1 + len2; i++)
    {
        printf("%c", new[i]);
    }
    return 0;
}
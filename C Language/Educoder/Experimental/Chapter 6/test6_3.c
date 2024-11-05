#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4
void strsort(char *s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j ++) {
            if (strcmp(s[j], s[j+1]) > 0) {
                char *temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}


int main() {
    int i, n;
    scanf("%d", &n);
    getchar();
    char *s[n], t[50];
    for (i = 0; i < n; i++) {
        fgets(t, sizeof(t), stdin);
        t[strcspn(t, "\n")] = '\0';
        s[i] = (char *)malloc(strlen(t) + 1);
        strcpy(s[i], t);
    }
    strsort(s, n);
    for (i = 0; i < n; i++)
    {
        puts(s[i]);
    }
}
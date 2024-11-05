#include <stdio.h>
#include <time.h>

void getTime(int *p);
int main() {
    int sec = 0;
    getTime(&sec);
    printf("%d", sec);
}

void getTime(int *p) {
    *p =time (NULL);
}
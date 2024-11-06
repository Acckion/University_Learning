#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);

    unsigned char *p = (unsigned char *)&num;

    for (int i = sizeof(num) - 1; i >= 0; i--) {
        int temp = *(p + i);
        int high = temp & 0x0f;
        int low = (temp >> 4) & 0x0f;
        printf("%x %x ", low, high);
    }
    return 0;
}
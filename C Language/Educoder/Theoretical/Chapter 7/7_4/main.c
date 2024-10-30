#include "func.h"
#define SIZE 100

int main()
{
    /**********  Begin  **********/
    int n;
    char arr[SIZE];
    char out[SIZE];
    scanf("%[^\n]", &arr);
    scanf("%d", &n);
    strnCpy(out, arr, n);
    printf("%s", out);
    /**********  Begin  **********/
    return 0;
}

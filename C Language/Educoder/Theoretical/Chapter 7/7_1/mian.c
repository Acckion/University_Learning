#include "func.c"
#define SIZE 100
void inArray(int arr[], int n);
void selectSort(int arr[], int n);
void outArray(int arr[], int n);
int main()
{
    /**********  Begin  **********/
    int arr[SIZE], n, i;
    scanf("%d", &n); // 输入元素个数

    inArray(arr, n); // 输入数组的n个元素

    selectSort(arr, n); //  对数组元素排序

    outArray(arr, n); // 输出数组的n个元素

    /**********  End  **********/
    return 0;
}

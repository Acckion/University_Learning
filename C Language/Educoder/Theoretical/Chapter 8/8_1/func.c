#include <stdio.h>
// 冒泡升序排序 ，程序的输入为 int类型数组 和数组长度
// 请在此处编辑您的代码
/**********  Begin  **********/
void bubble_sort(int *a, int n)
{
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++)
        {
            if (*(a+j) > *(a + j+1))
            {
                int temp = *(a+j);
                *(a+j) = *(a + j+1);
                *(a +j+1) = temp;
            }
        }
    }
}
/**********  End  **********/

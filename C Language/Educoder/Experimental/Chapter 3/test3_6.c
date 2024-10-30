/*n位数平方的末尾n位和原数相同
任务描述
本关任务：实验课本P85  程序设计第（2）题
输入一个n位数(1≤n≤4)，若n位数平方的末尾n位和原数相同，则输出该数。找出所有满足该要求的n位数。

编程要求
在右侧编辑器补充代码，使之满足任务描述。

测试说明
平台会对你编写的代码进行测试：

测试输入：1；
预期输出：1 5 6;

测试输入：3；
预期输出：376 625;

开始你的任务吧，祝你成功！*/

#include<stdio.h>

int tail(int x, int n) {
    int result=0;
    int multiplier=1;
    for (int i=0; i<n; i++) {
        result += (x % 10)*multiplier;
        multiplier *= 10;
        x /= 10;
    }
    return result;
}

int main() {
    int x,n;
    scanf("%d %d", &x, &n);
    printf("%d", tail(x, n));
    return 0;
}
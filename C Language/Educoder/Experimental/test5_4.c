/*
任务描述
本关任务：完善实验指导书P142的求解约瑟夫问题的源程序：M个人围成一圈，
         从第一个人开始一次从1至N报数，每当报数为N时报数人出圈，
         直到圈中只剩下一个人为止。
*/

#include<stdio.h>

void joseph(int m, int n);

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    joseph(m, n);
    return 0;
}

void joseph(int m, int n) {
    int list[m];
    for (int i = 0; i < m; i++) {
        list[i] = 0;
    }
    int count = 0;
    int out = 0;
    for (int i = 0;; i++) {
        i %= m;
        if (list[i] == 0) {
            count++;
            if (count == n) {
                list[i] = 1;
                out++;
                printf("%d      ", i + 1);
                count = 0;
            }
        } 
        if (out == m - 1)
            break;
    }
    for (int i = 0; i < m; i++) {
        if (list[i] == 0) {
            printf("\n%d", i + 1);
            break;
        }
    }
}

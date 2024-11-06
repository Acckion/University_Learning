#include <stdio.h>
#include <string.h>

void scheduler();
void execute(int);
char list[100];

void task1(){
    printf("task1 is called!\n");
}
void task2()
{
    printf("task2 is called!\n");
}
void task3()
{
    printf("task3 is called!\n");
}
void task4()
{
    printf("task4 is called!\n");
}
void task5()
{
    printf("task5 is called!\n");
}
void task6()
{
    printf("task6 is called!\n");
}
void task7()
{
    printf("task7 is called!\n");
}
void task0()
{
    printf("task0 is called!\n");
}
void (*p[8])(void) = {task0, task1, task2, task3, task4, task5, task6, task7};

int main() {
    scanf("%s", list);
    scheduler();
    return 0;
}
void scheduler() {
    for (int i = 0; i < strlen(list); i++)
    {
        int n = list[i] - '0';
        execute(n);
        }
}
void execute(int m) {
    p[m]();
}

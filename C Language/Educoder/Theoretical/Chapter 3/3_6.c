/*输出对应年份的各月名称及天数
任务描述
本关任务：定义枚举类型enum month，一月（Jan），二月（Feb）、......、十二月（Dec）。编写一个程序，能根据输入的年份值，输出对应该年份各月的英文名称及天数，（注：此题没有特别限制，没有学到后续章节的同学，可以逐月顺序处理，使用条件运算符完成判断是否为闰年处理）。

相关知识
为了完成本关任务，你需要掌握：

枚举类型；
闰年判断；
条件判断语句。
编程要求
根据提示，在右侧编辑器Begin-End中编写程序，编写一个能根据年份输出对应年份各月的英文名称及天数的函数。输出要求为：各月份英文名称需要输出全称，并且月份首字母大写。然后月份后面跟上冒号（:）,然后跟上一个空格，后面是对应月份的天数，每月输出一行，具体格式见测试用例。

测试说明
平台会对你编写的代码进行测试：

测试输入：2000；
预期输出：

Jan: 31
Feb: 29
Mar: 31
Apr: 30
May: 31
Jun: 30
Jul: 31
Aug: 31
Sep: 30
Oct: 31
Nov: 30
Dec: 31
测试输入：2019；

预期输出：

Jan: 31
Feb: 28
Mar: 31
Apr: 30
May: 31
Jun: 30
Jul: 31
Aug: 31
Sep: 30
Oct: 31
Nov: 30
Dec: 31
开始你的任务吧，Showtime！*/

#include <stdio.h>

int main()
{
    /**********Begin**********/
    int year;
    scanf("%d", &year);

    enum month
    {
        Jan,
        Feb,
        Mar,
        Apr,
        May,
        Jun,
        Jul,
        Aug,
        Sep,
        Oct,
        Nov,
        Dec
    };

    int is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (is_leap)
    {
        days[Feb] = 29;
    }

    printf("Jan: %d\nFeb: %d\nMar: %d\nApr: %d\nMay: %d\nJun: %d\nJul: %d\nAug: %d\nSep: %d\nOct: %d\nNov: %d\nDec: %d\n", days[0], days[1], days[2], days[3], days[4], days[5], days[6], days[7], days[8], days[9], days[10], days[11]);
    /**********End**********/
    return 0;
}

 #include<stdio.h>

 int main()
 {
    int x=0, n=0;
    scanf("%d %d", &x, &n);
    int new_int = ((unsigned)x>>n) | ((unsigned)x<<(32 - n)); //运算中整形，以使右移为逻辑右移而非算数右移
    printf("%d", new_int);
    return 0;
 }

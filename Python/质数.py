num = int(input("请输入一个数："))
a = 2
while a < num:
    if num % a != 0:
        a += 1
    else:
        print(f"{num}不是质数")
        break
if a == num:
    print(f"{num}是质数")

     +++
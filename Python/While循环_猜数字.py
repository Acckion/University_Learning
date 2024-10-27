# 猜数字游戏(while循环)

# 随机数
import random
num = random.randint(1, 100)

i = 1
flag = True
while flag:
    guest = int(input(f"第{i}次猜数字:"))
    if guest == num:
        flag = False
        print(f"恭喜你用{i}次猜对了")
        print("游戏成功")
    else:
        if guest < num:
            print("你猜的数字偏小")
        else:
            print("你猜的数字偏大")
    i += 1


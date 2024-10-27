# 猜数字游戏
target_num = int(input("目标数字:"))
num1 = int(input("第1次猜数字"))
if num1 == target_num:
    print("正确")
else:
    if num1 <= target_num:
        print("错误，偏小")
    if num1 >= target_num:
        print("错误，偏大")

    num2 = int(input("第2次猜数字"))
    if num2 == target_num:
        print("正确")
    else:
        if num2 <= target_num:
            print("错误，偏小")
        if num2 >= target_num:
            print("错误，偏大")

        num3 = int(input("第3次猜数字"))
        if num3 == target_num:
            print("正确")
        else:
            if num3 <= target_num:
                print("错误，偏小")
            if num3 >= target_num:
                print("错误，偏大")
            print("游戏结束")

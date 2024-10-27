# 发工资案例
cash = 26900
n = 0
for n in range(1, 21):
    import random
    num = random.randint(1, 10)
    if num >= 5:
        if cash >= 2000:
            cash -= 2000
            print(f"员工{n}发工资2000，余额{cash}")
        else:
            print(f"员工{n}发工资{cash}，余额0")
            cash = 0
    elif num >= 3:
        if cash >= 1000:
            cash -= 1000
            print(f"员工{n}发工资1000，余额{cash}")
        else:
            print(f"员工{n}发工资{cash}，余额0")
            cash = 0
    else:
        print(f"员工{n}绩效过低，跳过")
    if cash <= 0:
        print(f"余额不足，已发{n}人工资")
        break
if cash >= 0:
    if n == 20:
        print(f"工资已经发完，余额{cash}")


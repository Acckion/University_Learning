# print不换行
print("hello ", end='')
print("world")

# 对齐
print("hello\tworld")
print("Fang\tBoHan")

# while循环
i = 1
while i <= 9:
    j = 1
    while j <= i:
        print(f"{j}x{i}={i * j} \t", end='')
        j += 1
    i += 1
    print()

# for循环
for i in range(1, 20):
    if i == 4:
        continue
    if i == 10:
        break
    for j in range(1, i + 1):
        print(f"{i}x{j}={i * j}\t", end="")
    print()

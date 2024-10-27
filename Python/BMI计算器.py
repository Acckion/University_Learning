# BMI计算工具
BMI = float(input("Please enter your weight(kg):")) / (float(input("Please enter your height(m):")) ** 2)
print("Begin to caculate your BMI...")
print("Your BMI is", BMI)
if BMI < 20:
    print("Slim")
elif BMI <= 30:
    print("Normal")
else:
    print("Fat")

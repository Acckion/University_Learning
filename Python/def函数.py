def my_len(data):
    """
    len函数求文字个数
    :param data: 文字
    :return:  文字的个数
    """
    n = 0
    for x in data:
        n += 1
    return n


num = 0


def plus(a, b):
    """
    函数说明
    :param a: 参数a
    :param b: 参数b
    :return: 返回a+b
    """
    global num
    return a + b


print(plus(25, 65))
print(my_len("Fang"))

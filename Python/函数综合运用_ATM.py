
def main_menu():
    global user_name
    print("----------主菜单----------")
    print(f"欢迎用户{user_name}使用ATM")
    print("按1查询余额")
    print("按2存款")
    print("按3取款")
    print("按4退出账户")
    act = int(input("请按键盘选择对应功能："))
    if act == 1:
        print("开始查询余额...")
        print()
        check_balance()

    elif act == 2:
        print("开始存款...")
        print()
        save()
    elif act == 3:
        print("开始取款...")
        print()
        draw()
    elif act == 4:
        print("返回主菜单...")
        print()
        log_in()
    else:
        print("输入错误，请重新输入...")
        print()
        main_menu()


def check_balance():
    global balance
    print("---------余额查询---------")
    print(f"您的余额为{balance}元")
    print()
    print("按1返回主菜单")
    print("按2退出登录")
    act = int(input("请按键盘选择对应功能："))
    if act == 1:
        main_menu()
    if act == 2:
        log_in()


def log_in():
    global user_name, balance
    print("---------请登录----------")
    user_name = input("请输入您的用户名：")
    balance = 500000
    main_menu()


def save():
    global balance
    print("----------存款----------")
    mount = int(input("请输入存款金额："))
    insure = input(f"存款金额为{mount},确认请按1，取消请按其他任意键：")
    if insure == "1":
        balance += mount
        print(f"您已存入{mount},当前余额为{balance}")
    else:
        print("您已取消")
    print("按1返回主菜单")
    print("按2退出登录")
    print("按3再次存款")
    act = int(input("请按键盘选择对应功能："))
    if act == 1:
        main_menu()
    if act == 2:
        log_in()
    if act == 3:
        save()


def draw():
    global balance
    print("----------取款----------")
    mount = int(input("请输入取款金额："))
    insure = input(f"取款金额为{mount},确认请按1，取消请按其他任意键：")
    if insure == "1":
        balance -= mount
        print(f"您已取出{mount},当前余额为{balance}")
    else:
        print("您已取消")
    print("按1返回主菜单")
    print("按2退出登录")
    print("按3再次取款 ")
    act = int(input("请按键盘选择对应功能："))
    if act == 1:
        main_menu()
    if act == 2:
        log_in()
    if act == 3:
        darw()



user_name = None
balance = 50000
log_in()


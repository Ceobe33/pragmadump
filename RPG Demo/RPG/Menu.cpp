#include "stdafx.h"
#include "Menu.h"
#include "RoleSelect.h"

#include <array>

void cpptest4()
{
    // 1. 如何声明下述数据
    //   a. actor 是由30个 char 组成的数组.
    char actor[30]{};
    //   b. betsie 是由100个 short 组成的数组.
    short betsie[100]{};
    //   c. chuck 是由13个 float 组成的数组.
    float chuck[13]{};
    //   d. dipsea 是由64个 long double 组成的数组.
    long double dipsea[64]{};
    // 2. 使用模板类 array 而不是数组来完成问题1.
    array<char, 30> actor1{};
    array<short, 100> betsie1{};
    array<float, 13> chuck1{};
    array<long double, 64> dipsea1{};
    // 3. 声明一个包含5个元素的 int 数组,并将它初始化为5个正奇数.
    array<int, 5> odds{ 1, 3, 5, 7, 9 };
    array<int, 5> odds1{};
    size_t length = 5;
    int num = 1, cnt = 0;
    while (cnt < length)
    {
        if (num % 2 != 0) {
            odds1[cnt] = num;
            cnt++;
        }
        num++;
    }
    debug.prints("\nfirst five odd number:\t");
    for (int i : odds1)
    {
        debug.prints(i, "\t");
    }
    // 4. 编写一条语句，将问题3中数组第一个元素和最后一个元素的和赋给变量 even.
    int even = odds1.front() + odds1.back();
    debug.prints("\n", even);
    // 5. 编写一条语句，显示 float 数组 ideas 中的第二个元素的值.
    // debug.prints("\n", ideas[1]);
    // 6. 声明一个 char 数组, 并将其初始化为字符串 "cheeseburger".
    array<char, 30> str{ "cheeseburger" };
    // 7. 声明一个 string 对象, 并将其初始化为字符串 "Waldorf Salad".
    string str1{ "Waldorf Salad" }; // string str1 = "Waldorf Salad";
    // 8. 设计一个描述鱼的结构声明. 结构中应当包括品种, 重量(整数, 单位为盎司)和长度(英寸, 包括小数).
    struct Fish
    {
        Fish(string cate, int wei, float leng) {
            category = cate;
            weight = wei;
            length = leng;
        }
        string category{};
        int weight{};
        float length{};
    };
    // 9. 声明一个问题8中定义的结构的变量,并对它进行初始化.
    Fish grassFish = Fish("grass", 5, 10.0f);
    // 10. 用 enum 定义一个名为 Response 的类型,它包含 Yes, No 和 Maybe 等枚举量,其中 Yes 的值为1, No 为0, Maybe 为2.
    enum Response
    {
        No,
        Yes,
        Maybe
    };
    // 11. 假设 ted 是一个 double 变量，请声明一个指向 ted 的指针，并使用该指针来显示 ted 的值.
    double ted = 3.0f;
    double* ptr = &ted;
    debug.prints("\n", * ptr);
    // 12. 假设 treacle 是一个包含10个元素的 float 数组,请声明一个指向 treacle 的第一个元素的指针,并使用该指针来显示数组的第一个元素和最后一个元素.
    array<float, 10> treacle{ 1, 2,3,4,5,6,7,8,9,10 };
    float* ptrf = &treacle[0];
    debug.prints("\n", *ptrf, " ", * (ptrf + 9));
    // 13. 编写一段代码,要求用户输入一个正整数,然后创建一个动态的 int 数组,其中包含的元素数目等于用户输入的值. 首先使用 new 来完成这项任务,再使用 vector 对象来完成这项任务.
    int size = 5;
    // cin >> size;
    int* arr1 = new int[size];
    // 14. 下面的代码是否有效？如果有效，它将打印出什么结果？
    // cout << (int *) "Home of the jolly bytes";
    // 15. 编写一段代码,给问题8中描述的结构动态分配内存,再读取该结构的成员的值.
    // 16. 程序清单4.6 指出了混合输入数字和一行字符串时存储的问题.如果将代码 `cin.getline(address, 80);` 替换为 `cin >> address;` 将对程序的运行带来什么影响?
    // answer: 会造成程序崩溃，cin 会尝试写入 address 直到清空用户输入，当 address 容量不够时，会出现越界的情况
    /* 程序清单 4.6 numstr.cpp
        // numstr.cpp -- following number input with line input
        #include <iostream>
        int main() {
            using namespace std;
            cout << "What year was your house built?\n";
            int year;
            cin >> year;
            char address[80];
            cin.getline(address, 80);
            cout << "Year built: " << year << endl;
            cout << "Address: " << address << endl;
            cout << "Done!\n";
            return 0;
        }
    */
    // 17. 声明一个 vector 对象和一个 array 对象,它们都包含10个 string 对象.指出所需要的头文件,但不要使用 using.使用 const 来指定要包含的 string 对象数.
    std::vector<string> vecStr[10]{};
    std::array<string, 10> arrayStr{};

}

void sorts() {

}

cMenu::cMenu() {
    m_strName = "Menu";
}

void cMenu::update() {
    if (KEY_DOWN(VK_RETURN)) {
        cDirector::getInstance()->pushScene(this);
        cDirector::getInstance()->pushScene(new cRoleSelectRuler());
    }
}

void cMenu::render() {
    cout << "\n\n\t            this is Menu\n"
        << "\t        press enter to play";
    cpptest4();
}

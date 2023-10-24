#include "stdafx.h"
#include "Menu.h"
#include "RoleSelect.h"

#include <array>

void cpptest4()
{
    // 1. ���������������
    //   a. actor ����30�� char ��ɵ�����.
    char actor[30]{};
    //   b. betsie ����100�� short ��ɵ�����.
    short betsie[100]{};
    //   c. chuck ����13�� float ��ɵ�����.
    float chuck[13]{};
    //   d. dipsea ����64�� long double ��ɵ�����.
    long double dipsea[64]{};
    // 2. ʹ��ģ���� array �������������������1.
    array<char, 30> actor1{};
    array<short, 100> betsie1{};
    array<float, 13> chuck1{};
    array<long double, 64> dipsea1{};
    // 3. ����һ������5��Ԫ�ص� int ����,��������ʼ��Ϊ5��������.
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
    // 4. ��дһ����䣬������3�������һ��Ԫ�غ����һ��Ԫ�صĺ͸������� even.
    int even = odds1.front() + odds1.back();
    debug.prints("\n", even);
    // 5. ��дһ����䣬��ʾ float ���� ideas �еĵڶ���Ԫ�ص�ֵ.
    // debug.prints("\n", ideas[1]);
    // 6. ����һ�� char ����, �������ʼ��Ϊ�ַ��� "cheeseburger".
    array<char, 30> str{ "cheeseburger" };
    // 7. ����һ�� string ����, �������ʼ��Ϊ�ַ��� "Waldorf Salad".
    string str1{ "Waldorf Salad" }; // string str1 = "Waldorf Salad";
    // 8. ���һ��������Ľṹ����. �ṹ��Ӧ������Ʒ��, ����(����, ��λΪ��˾)�ͳ���(Ӣ��, ����С��).
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
    // 9. ����һ������8�ж���Ľṹ�ı���,���������г�ʼ��.
    Fish grassFish = Fish("grass", 5, 10.0f);
    // 10. �� enum ����һ����Ϊ Response ������,������ Yes, No �� Maybe ��ö����,���� Yes ��ֵΪ1, No Ϊ0, Maybe Ϊ2.
    enum Response
    {
        No,
        Yes,
        Maybe
    };
    // 11. ���� ted ��һ�� double ������������һ��ָ�� ted ��ָ�룬��ʹ�ø�ָ������ʾ ted ��ֵ.
    double ted = 3.0f;
    double* ptr = &ted;
    debug.prints("\n", * ptr);
    // 12. ���� treacle ��һ������10��Ԫ�ص� float ����,������һ��ָ�� treacle �ĵ�һ��Ԫ�ص�ָ��,��ʹ�ø�ָ������ʾ����ĵ�һ��Ԫ�غ����һ��Ԫ��.
    array<float, 10> treacle{ 1, 2,3,4,5,6,7,8,9,10 };
    float* ptrf = &treacle[0];
    debug.prints("\n", *ptrf, " ", * (ptrf + 9));
    // 13. ��дһ�δ���,Ҫ���û�����һ��������,Ȼ�󴴽�һ����̬�� int ����,���а�����Ԫ����Ŀ�����û������ֵ. ����ʹ�� new �������������,��ʹ�� vector �����������������.
    int size = 5;
    // cin >> size;
    int* arr1 = new int[size];
    // 14. ����Ĵ����Ƿ���Ч�������Ч��������ӡ��ʲô�����
    // cout << (int *) "Home of the jolly bytes";
    // 15. ��дһ�δ���,������8�������Ľṹ��̬�����ڴ�,�ٶ�ȡ�ýṹ�ĳ�Ա��ֵ.
    // 16. �����嵥4.6 ָ���˻���������ֺ�һ���ַ���ʱ�洢������.��������� `cin.getline(address, 80);` �滻Ϊ `cin >> address;` ���Գ�������д���ʲôӰ��?
    // answer: ����ɳ��������cin �᳢��д�� address ֱ������û����룬�� address ��������ʱ�������Խ������
    /* �����嵥 4.6 numstr.cpp
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
    // 17. ����һ�� vector �����һ�� array ����,���Ƕ�����10�� string ����.ָ������Ҫ��ͷ�ļ�,����Ҫʹ�� using.ʹ�� const ��ָ��Ҫ������ string ������.
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

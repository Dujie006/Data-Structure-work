#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

// 功能1：比较两个字符串
void compareStrings() {
    string s1, s2;
    cout << "请输入第一个字符串: ";
    cin >> s1;
    cout << "请输入第二个字符串: ";
    cin >> s2;

    if (s1 == s2) {
        cout << "两个字符串相等" << endl;
    } else if (s1 > s2) {
        cout << "第一个字符串大于第二个字符串" << endl;
    } else {
        cout << "第一个字符串小于第二个字符串" << endl;
    }
}

// 功能2：删除字符串中指定的字符
void deleteChar() {
    string str;
    char ch;
    cout << "请输入一个字符串: ";
    cin >> str;
    cout << "请输入要删除的字符: ";
    cin >> ch;

    // 遍历字符串，删除所有等于 ch 的字符
    string result;
    for (char c : str) {
        if (c != ch) {
            result += c;
        }
    }

    cout << "删除后的字符串: " << result << endl;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int choice;
    do {
        cout << "\n===== 菜单 =====" << endl;
        cout << "1. 比较两个字符串" << endl;
        cout << "2. 删除字符串中的指定字符" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择: ";
        cin >> choice;

        switch (choice) {
            case 1:
                compareStrings();
                break;
            case 2:
                deleteChar();
                break;
            case 0:
                cout << "程序退出，再见！" << endl;
                break;
            default:
                cout << "无效选择，请重新输入！" << endl;
        }
    } while (choice != 0);

    return 0;
}
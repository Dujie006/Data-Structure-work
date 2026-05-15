#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int findSubstring(const string& str, int start, const string& sub) {
    int len = str.length();
    if (start < 1 || start > len) return 0;
    size_t pos = str.find(sub, start - 1);
    if (pos == string::npos) return 0;
    return pos + 1;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    string mainStr, subStr;
    int start;
    
    cout << "请输入主串: ";
    getline(cin, mainStr);
    cout << "请输入起始位置（从1开始）: ";
    cin >> start;
    cin.ignore();
    cout << "请输入要检索的子串: ";
    getline(cin, subStr);
    
    int pos = findSubstring(mainStr, start, subStr);
    if (pos != 0) {
        cout << "子串 \"" << subStr << "\" 出现在位置 " << pos << endl;
    } else {
        cout << "未找到子串" << endl;
    }
    return 0;
}
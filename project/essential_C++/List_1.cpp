#include <iostream>
#include <windows.h>
using namespace std;
const int MAXSIZE = 10000; // 线性表最大容量
class SeqList {
private:
    int data[MAXSIZE]; // 存储元素的数组
    int length;        // 当前线性表长度
public:
    // 构造函数：初始化空表
    SeqList() {
        length = 0;
    }
    // 插入元素：在位置pos（1-based）插入元素elem
    bool insert(int pos, int elem) {
        // 1. 检查位置是否有效（1 <= pos <= length+1）
        if (pos < 1 || pos > length + 1) {
            cout << "插入位置无效！" << endl;
            return false;
        }
        // 2. 检查表是否已满
        if (length >= MAXSIZE) {
            cout << "线性表已满，无法插入！" << endl;
            return false;
        }
        // 3. 将pos位置及之后的元素后移一位
        for (int i = length; i >= pos; i--) {
            data[i] = data[i - 1];
        }
        // 4. 插入新元素
        data[pos - 1] = elem;
        // 5. 表长增加
        length++;
        return true;
    }
    // 输出线性表中所有元素
    void display() {
        if (length == 0) {
            cout << "线性表为空" << endl;
            return;
        }
        cout << "线性表内容：";
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
// 主函数演示插入操作
int main() {
    SetConsoleOutputCP(CP_UTF8);   // 设置控制台输出为 UTF-8
    SetConsoleCP(CP_UTF8);         // 设置控制台输入为 UTF-8
    SeqList list;
    cout << "我是杜杰" << endl;
    int n;
    cin >> n ;
    // 先插入几个元素建立初始表
    list.insert(1, n); // 位置1插入10
    list.insert(2, 20); // 位置2插入20
    list.insert(3, 30); // 位置3插入30
    cout << "初始表：" << endl;
    list.display();
    // 在位置2插入元素25
    cout << "\n在位置2插入元素25：" << endl;
    if (list.insert(2, 25)) {
        list.display();
    }
    // 在位置1插入元素5
    cout << "\n在位置1插入元素5：" << endl;
    if (list.insert(1, 5)) {
        list.display();
    }
    // 在末尾（位置5）插入元素40
    cout << "\n在末尾插入元素40：" << endl;
    if (list.insert(5, 40)) {
        list.display();
    }
    // 尝试插入非法位置（如位置0）
    cout << "\n尝试在位置0插入99：" << endl;
    list.insert(0, 99);
    return 0;
}
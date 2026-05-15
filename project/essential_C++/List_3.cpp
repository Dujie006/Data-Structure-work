#include <iostream>
#include <windows.h>
using namespace std;
const int MAXSIZE = 100; // 栈的最大容量
class SeqStack {
private:
    int data[MAXSIZE]; // 存放栈元素的数组
    int top;           // 栈顶指针（指向栈顶元素的下标，-1表示空栈）
public:
    // 构造函数：创建一个空栈
    SeqStack() : top(-1) {}
    // 判断栈是否为空
    bool isEmpty() {
        return top == -1;
    }
    // 判断栈是否已满
    bool isFull() {
        return top == MAXSIZE - 1;
    }
    // 入栈操作
    bool push(int elem) {
        if (isFull()) {
            cout << "栈已满，无法入栈！" << endl;
            return false;
        }
        data[++top] = elem;
        cout << "元素 " << elem << " 入栈成功。" << endl;
        return true;
    }
    // 出栈操作
    bool pop() {
        if (isEmpty()) {
            cout << "栈为空，无法出栈！" << endl;
            return false;
        }
        cout << "元素 " << data[top--] << " 出栈成功。" << endl;
        return true;
    }
    // 获取栈顶元素（但不删除）
    bool getTop(int &elem) {
        if (isEmpty()) {
            cout << "栈为空，无栈顶元素。" << endl;
            return false;
        }
        elem = data[top];
        return true;
    }
    // 显示栈中所有元素（从栈底到栈顶）
    void display() {
        if (isEmpty()) {
            cout << "栈为空" << endl;
            return;
        }
        cout << "栈的内容（从栈底到栈顶）：";
        for (int i = 0; i <= top; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
// 主函数演示栈操作
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SeqStack stack;  // 创建一个空栈
    // 1. 入栈操作
    cout << "=== 入栈操作 ===" << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    // 2. 出栈操作
    cout << "\n=== 出栈操作 ===" << endl;
    stack.pop();
    stack.display();
    // 3. 再入栈一个元素
    cout << "\n=== 继续入栈 ===" << endl;
    stack.push(40);
    stack.display();
    // 4. 获取栈顶元素
    int topElem;
    if (stack.getTop(topElem)) {
        cout << "当前栈顶元素是：" << topElem << endl;
    }
    // 5. 连续出栈至空
    cout << "\n=== 连续出栈 ===" << endl;
    stack.pop();
    stack.pop();
    stack.pop(); // 尝试从空栈出栈
    stack.display();
    return 0;
}
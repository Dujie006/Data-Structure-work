#include <iostream>
#include <windows.h>
using namespace std;
// 结点结构
struct Node {
    int data;   // 数据域
    Node* next; // 指针域
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList {
private:
    Node* head; // 头指针（指向第一个结点）
public:
    // 构造函数：初始化空链表
    LinkedList() : head(nullptr) {}
    // 析构函数：释放所有结点内存
    ~LinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    // 尾部插入结点（用于构建链表）
    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    // 按位置删除结点（位置从1开始计数）
    bool removeByPos(int pos) {
        if (head == nullptr) {
            cout << "链表为空，无法删除！" << endl;
            return false;
        }
        if (pos < 1) {
            cout << "删除位置无效（应 >= 1）！" << endl;
            return false;
        }
        // 删除头结点
        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "成功删除位置 " << pos << " 的结点。" << endl;
            return true;
        }
        // 寻找第 pos-1 个结点
        Node* prev = head;
        int count = 1;
        while (prev != nullptr && count < pos - 1) {
            prev = prev->next;
            count++;
        }
        // 检查结点是否存在
        if (prev == nullptr || prev->next == nullptr) {
            cout << "删除位置 " << pos << " 超出链表长度！" << endl;
            return false;
        }
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        cout << "成功删除位置 " << pos << " 的结点。" << endl;
        return true;
    }
    // 按值删除第一个匹配的结点
    bool removeByVal(int val) {
        if (head == nullptr) {
            cout << "链表为空，无法删除！" << endl;
            return false;
        }
        // 如果头结点就是要删除的结点
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "成功删除值为 " << val << " 的第一个结点。" << endl;
            return true;
        }
        // 查找后继结点
        Node* prev = head;
        while (prev->next != nullptr && prev->next->data != val) {
            prev = prev->next;
        }
        if (prev->next == nullptr) {
            cout << "未找到值为 " << val << " 的结点！" << endl;
            return false;
        }
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        cout << "成功删除值为 " << val << " 的第一个结点。" << endl;
        return true;
    }
    // 输出链表所有结点
    void display() {
        if (head == nullptr) {
            cout << "链表为空" << endl;
            return;
        }
        cout << "链表内容：";
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
// 主函数演示删除操作
int main() {
    SetConsoleOutputCP(CP_UTF8);   // 设置控制台输出为 UTF-8
    SetConsoleCP(CP_UTF8);         // 设置控制台输入为 UTF-8
    LinkedList list;
    // 先建立链表：1->2->3->4->5
    for (int i = 1; i <= 5; i++) {
        list.append(i);
    }
    cout << "初始链表：" << endl;
    list.display();
    // 1. 按位置删除：删除第3个结点（值为3）
    cout << "\n删除位置3的结点：" << endl;
    list.removeByPos(3);
    list.display();
    // 2. 按位置删除：删除头结点（位置1）
    cout << "\n删除位置1的结点：" << endl;
    list.removeByPos(1);
    list.display();
    // 3. 按值删除：删除值为5的结点
    cout << "\n删除值为5的结点：" << endl;
    list.removeByVal(5);
    list.display();
    // 4. 删除不存在的值
    cout << "\n尝试删除值为100的结点：" << endl;
    list.removeByVal(100);
    list.display();
    // 5. 删除超出范围的位置
    cout << "\n尝试删除位置10的结点：" << endl;
    list.removeByPos(10);
    return 0;
}
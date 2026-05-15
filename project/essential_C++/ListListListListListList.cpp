#include <iostream>
using namespace std;

// 单链表节点
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// 创建单链表（尾插法）
Node* createList() {
    int n, val;
    cout << "请输入单链表的元素个数: ";
    cin >> n;
    if (n <= 0) return nullptr;
    
    Node* head = nullptr;
    Node* tail = nullptr;
    cout << "请输入 " << n << " 个整数: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// 查找元素
bool search(Node* head, int target) {
    Node* cur = head;
    while (cur) {
        if (cur->data == target) return true;
        cur = cur->next;
    }
    return false;
}

// 释放链表内存
void deleteList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Node* list = createList();
    if (!list) {
        cout << "链表为空" << endl;
        return 0;
    }
    
    int target;
    cout << "请输入要查找的元素: ";
    cin >> target;
    
    bool found = search(list, target);
    cout << (found ? "True" : "False") << endl;
    
    deleteList(list);
    return 0;
}
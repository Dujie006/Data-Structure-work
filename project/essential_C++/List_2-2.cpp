#include <iostream>
#include <windows.h>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

DNode* createCircularList() {
    int n, val;
    cout << "请输入双循环链表的元素个数: ";
    cin >> n;
    if (n <= 0) return nullptr;
    
    DNode* head = nullptr;
    DNode* tail = nullptr;
    cout << "请输入 " << n << " 个整数: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        DNode* newNode = new DNode(val);
        if (!head) {
            head = tail = newNode;
            head->prev = head->next = head;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }
    return head;
}

DNode* insertBefore(DNode* head, int pos, int val) {
    if (!head) {
        if (pos == 1) {
            DNode* newNode = new DNode(val);
            newNode->prev = newNode->next = newNode;
            return newNode;
        }
        cout << "链表为空，只能在位置1插入" << endl;
        return nullptr;
    }
    
    int len = 0;
    DNode* cur = head;
    do {
        ++len;
        cur = cur->next;
    } while (cur != head);
    
    if (pos < 1 || pos > len + 1) {
        cout << "位置无效，有效范围: 1 ~ " << len + 1 << endl;
        return head;
    }
    
    DNode* newNode = new DNode(val);
    if (pos == 1) {
        DNode* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        return newNode;
    }
    
    cur = head;
    for (int i = 1; i < pos; ++i) cur = cur->next;
    DNode* prevNode = cur->prev;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = cur;
    cur->prev = newNode;
    return head;
}

void printList(DNode* head) {
    if (!head) {
        cout << "空链表" << endl;
        return;
    }
    DNode* cur = head;
    cout << "链表内容: ";
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);
    cout << endl;
}

void deleteList(DNode* head) {
    if (!head) return;
    DNode* cur = head;
    DNode* nextNode;
    do {
        nextNode = cur->next;
        delete cur;
        cur = nextNode;
    } while (cur != head);
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    DNode* list = createCircularList();
    if (list) {
        cout << "原";
        printList(list);
    } else {
        cout << "链表为空" << endl;
    }
    
    int pos, val;
    cout << "请输入插入位置（第几个节点之前）: ";
    cin >> pos;
    cout << "请输入要插入的元素值: ";
    cin >> val;
    
    list = insertBefore(list, pos, val);
    if (list) {
        cout << "插入后";
        printList(list);
        deleteList(list);
    }
    return 0;
}
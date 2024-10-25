#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

/*
 *  深拷贝 分为三步走 1.拷贝 2.插入 3.分开
 * */
Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;

    // 1.拷贝
    Node* curr = head;
    while (curr) {
        Node* node = new Node(curr->val);
        node->next = curr->next;
        curr->next = node;
        curr = curr->next->next;
    }

    // 2.插入
    curr = head;
    while (curr) {
        if (curr->random) curr->next->random = curr->random->next;
        curr =curr->next->next;
    }

    // 3.分开
    curr = head;
    Node* copyHead = curr->next;
    Node* copycurr = copyHead;
    while (curr) {
        curr->next = curr->next->next;
        if (copycurr->next) copycurr->next = copycurr->next->next;
        curr = curr->next;
        copycurr = copycurr->next;
    }
    return copyHead;
}

void printNode (Node* head) {
    Node* curr = head;
    cout << "按照next打印：";
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    curr = head;
    cout << "按照random打印：";
    while (curr) {
        if (curr->random) {
            cout << curr->random->val << " ";
        } else {
            cout << "null ";
        }
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // 创建链表节点
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    // 设置 next 指针
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // 设置 random 指针
    node1->random = node3;  // node1.random -> node3
    node2->random = node1;  // node2.random -> node1
    node3->random = node4;  // node3.random -> node4
    node4->random = nullptr;  // node4.random -> null

    // 打印原链表
    cout << "原链表：" << endl;
    printNode(node1);

    // 复制链表
    Node* copiedList = copyRandomList(node1);

    // 打印复制后的链表
    cout << "复制链表：" << endl;
    printNode(copiedList);

    // 清理内存
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
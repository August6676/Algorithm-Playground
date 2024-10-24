#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x): val(x),next(nullptr) {}
    ListNode(int x,ListNode* next): val(x),next(next) {}
};

/*
 *  使用栈
 * */
ListNode* removeNthFromEnd1(ListNode* head, int n) {
    stack<ListNode*> nodeStack;
    ListNode* current = head;

    while (current) {
        nodeStack.push(current);
        current = current->next;
    }

    // 如果要删除的是头节点
    if (n == nodeStack.size()) return head->next;

    // 找到要删除的前一个节点
    for (int i = 0; i < n; i++) {
        nodeStack.pop();
    }
    ListNode* prevNode = nodeStack.top();
    ListNode* nodeToDelete = prevNode->next;
    prevNode->next = nodeToDelete->next;
    // 释放空间
    delete nodeToDelete;

    return head;
}

/*
 *  双指针
 * */
ListNode* removeNthFromEnd2(ListNode* head, int n) {
    // 创建一个虚拟头节点 从n -> n+1
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;

    for (int i = 0; i <= n;i++) {
        first = first->next;
    }
    // 两个指针相差n+1的时候 再开始移动 一个到末尾 一个到被删节点的前一个
    while (first != nullptr) {
        first =first->next;
        second =second->next;
    }
    ListNode* nodeToDelete = second->next;
    second->next = nodeToDelete->next;
    delete nodeToDelete;
    delete dummy;

    return head;
}
// 辅助函数，用于打印链表
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // 创建一个链表 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    head = removeNthFromEnd2(head, 2); // 删除倒数第2个节点

    std::cout << "Updated list: ";
    printList(head);
}
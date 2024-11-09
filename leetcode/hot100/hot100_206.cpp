#include <iostream>

#include "ListNode.h"
using namespace std;

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev; // 当前节点指向前面
        prev = curr;
        curr = next; // 整体后移
    }
    return prev;
}

int main() {
    cout << "请输入链表长度:";
    int n;
    cin >> n;
    cout << "请输入链表元素（用空格分隔）:";
    ListNode* head = nullptr;
    ListNode* p_node = head;

    // cpp创建链表
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (i == 0) {
            head = new ListNode(val);
            p_node = head;
        } else {
            p_node->next = new ListNode(val);
            p_node = p_node->next;
        }
    }

    head = reverseList(head);

    cout << "反转后的链表：";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
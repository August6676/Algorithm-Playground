#include <iostream>

#include "ListNode.h"
using namespace std;


ListNode* getMid(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = nullptr; // 代表慢指针的前一个节点
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) prev->next = nullptr; // 从中间断开
    return slow;
}

ListNode* merge(ListNode* l1,ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* prev = dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            dummy->next = l1;
            l1 = l1->next;
        } else {
            dummy->next = l2;
            l2 = l2->next;
        }
        dummy = dummy->next;
    }

    dummy->next = l1 ? l1 : l2;
    ListNode* result = prev->next;
    delete prev;
    return result;
}

/*
 *  结合归并排序和双指针
 * */
ListNode* sortList(ListNode* head) {
    if (head == nullptr|| head->next == nullptr) return head;

    ListNode* mid = getMid(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);

    return merge(left,right);
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
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    cout << "Sorted list:";
    printList(sortList(head));
}
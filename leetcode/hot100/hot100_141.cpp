#include <iostream>
#include <unordered_set>
using namespace std;
#include "ListNode.h"
/*
 *Floyd判圈算法 快慢指针在环中一定相遇
 **/
bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    // 用do while循环可以让两者处在同一个起点 否则用while起点要不一样
    do {
        if (fast == nullptr || fast->next == nullptr) return false; // 这里如果用fast.next.next == nullptr会报错undefinedtype
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    return true;
}

int main() {
    auto* head = new ListNode(6);
    head->next = new ListNode(9);
    head->next->next = new ListNode(12);
    head->next->next->next = head->next;

    if (hasCycle(head)) cout << "是环形链表";
    else cout << "不是环形链表";
}
#include <iostream>
using namespace std;
#include "ListNode.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head1 = l1;
    ListNode* head2 = l2;
    ListNode* newhead = new ListNode(0); // newhead 在初始化时没有指向有效的内存，会导致未定义的行为，这里要分配空间
    ListNode* newNode = newhead;
    int uplift = 0; // 代表进位

    while (head1 != nullptr && head2 != nullptr) {
        int sum = head1->val + head2->val + uplift;
        ListNode* node;

        if (sum < 10) {
            node = new ListNode(sum);
            uplift = 0;
        } else {
            node = new ListNode(sum % 10);
            uplift = sum / 10;
        }
        newNode->next = node;
        newNode = newNode->next;
        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1 != nullptr) {
        int sum = head1->val + uplift;
        ListNode* node;

        if (sum < 10) {
            node = new ListNode(sum);
            uplift = 0;
        } else {
            node = new ListNode(sum % 10);
            uplift = sum / 10;
        }
        newNode->next = node;
        newNode = newNode->next;
        head1 = head1->next;
    }

    while (head2 != nullptr) {
        int sum = head2->val + uplift;
        ListNode* node;

        if (sum < 10) {
            node = new ListNode(sum);
            uplift = 0;
        } else {
            node = new ListNode(sum % 10);
            uplift = sum / 10;
        }
        newNode->next = node;
        newNode = newNode->next;
        head2 = head2->next;
    }

    if (uplift != 0) newNode->next = new ListNode(uplift);

    return newhead->next;
}

int main() {
    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);

    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);

    ListNode* head = addTwoNumbers(head1,head2);

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}
#include <iostream>
#include <stack>

#include "ListNode.h"
using namespace std;

/*
 * 确定反转次数
 * 分段反转
 */
ListNode* reverseList(ListNode* prev,int k) {
    ListNode* temp = prev->next;
    stack<ListNode*> nodeStack;
    for (int i = 0; i < k;i++) {
        nodeStack.push(temp);
        temp = temp->next;
    }
    ListNode* last = prev->next;
    while (!nodeStack.empty()) {
        prev->next = nodeStack.top();
        nodeStack.pop();
        prev = prev->next;
    }
    prev->next = temp;
    return prev; // 这里返回prev或者是last
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* temp = head;
    int length = 0;
    while (temp) {
        length++;
        temp = temp->next;
    }
    int count = length / k;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    for (int i = 0; i < count;i++) {
        prev = reverseList(prev,k);
    }

    return dummy->next;
}


int main() {
    int length,k;
    scanf("%d %d",&length,&k);

    ListNode* prev = new ListNode(0);
    ListNode* dummy = prev;

    for (int i = 1; i <= length;i++) {
        int x;
        scanf("%d",&x);
        prev->next = new ListNode(x);
        prev = prev->next;
    }
    ListNode* head = reverseKGroup(dummy->next,k);
    while (head) {
        printf("%d",head->val);
        head = head->next;
    }
}
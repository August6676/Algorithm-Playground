#include <iostream>
#include <deque>

#include "ListNode.h"
using namespace std;


bool isPalindrome(ListNode* head) {
    if (!head) return true;
    deque<int> dq;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        dq.push_back(curr->val);
        curr = next;
    }

    while (dq.size() > 1) {
        int front = dq.front();
        int back = dq.back();

        if (front != back) return  false;

        dq.pop_back();
        dq.pop_front();
    }
    return true;
}

int main() {
    int n;
    cout << "请输入链表的长度：";
    cin >> n;
    cout << "请输入列表的元素（空格分开）";

    ListNode* curr = nullptr;
    ListNode* head = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (i == 0) {
            head = new ListNode(val); // 如果仅仅是head->val = val;就是未初始化，没有分配内存。
            curr = head;
        } else {

            curr->next = new ListNode(val);
            curr = curr->next;
        }
    }
    bool flag = isPalindrome(head);

    if (flag) cout << "该链表为回文列表";
    else cout << "该链表不是回文列表";
}
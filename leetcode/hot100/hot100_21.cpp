#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode (): val(0),next(nullptr){}
    explicit ListNode (int x): val(x),next(nullptr){}
    ListNode (int x,ListNode* next): val(x),next(next){}
};

ListNode* mergeTwoLists(ListNode* list1,ListNode* list2) {
    ListNode* newNode = new ListNode(0);
    ListNode* curr = newNode;
    ListNode* first = list1;
    ListNode* second = list2;

    while (first != nullptr && second != nullptr) {
        if (first->val <= second->val) {
            curr->next = first;
            first = first->next;
        } else {
            curr->next = second;
            second = second->next;
        }
        curr = curr->next;
    }

    if (first == nullptr) curr->next = second;
    else curr->next = first;

    return newNode->next;
}

int main() {
    auto* list1 = new ListNode(3);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);
    list1->next->next->next = new ListNode(7);

    auto* list2 = new ListNode(0);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(3);
    list2->next->next->next = new ListNode(5);

    ListNode* ans = mergeTwoLists(list1,list2);
    cout << "合并后的链表元素为：";
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }

}
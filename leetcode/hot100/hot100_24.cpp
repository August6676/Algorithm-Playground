#include <iostream>
using namespace std;
/* 世界上美好的事情莫过于一次AC */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0),next(nullptr){}
    ListNode(int x): val(x),next(nullptr){}
    ListNode(int x,ListNode* next): val(x),next(next){}
};

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    // 增加一个前置节点
    ListNode* node0 = new ListNode(0);
    ListNode* prev = node0;
    prev->next = head;

    ListNode* first = head;
    ListNode* second = head->next;

    while (second != nullptr) {
        first->next = second->next;
        prev->next = second;
        second->next =first;

        prev = first;
        first = prev->next;
        if (first != nullptr) second = first->next;
        else break;
    }
    ListNode* result = node0->next;
    delete node0;
    return  result;
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

    head = swapPairs(head);

    std::cout << "Updated list: ";
    printList(head);
}
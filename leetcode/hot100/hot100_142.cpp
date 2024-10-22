#include <unordered_set>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(nullptr) {}
};

/*
 *  简单粗暴的哈希表，嗯嗯
 * */
ListNode* detectCycle1(ListNode* head) {
    unordered_set<ListNode*> hashset;
    ListNode* point = head;
    while (point != nullptr) {
        if (hashset.count(point)) return point;
        hashset.emplace(point);
        point = point->next;
    }
}

/*
 *  快慢指针 加上新指针
 * */
ListNode* detectCycle2(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    // 快慢指针相遇
    do {
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        fast = fast->next->next;
        slow = slow->next->next;
    } while (fast != slow);

    // 新指针和慢指针相遇
    ListNode* ptr = head;
    while (slow != ptr) {
        slow = slow->next;
        ptr = ptr->next;
    }
    return slow;
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;

    ListNode* startCycle = detectCycle1(head);
    cout << "环的入口点为：" << startCycle->val;
}
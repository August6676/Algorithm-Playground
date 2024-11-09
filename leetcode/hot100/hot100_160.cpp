#include <iostream>
#include <unordered_set>

#include "ListNode.h"
using namespace std;


/***
 * method 1: 双指针法
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr; // 为空的情况肯定不相交

    ListNode *pA = headA, *pB = headB;

    while (pA != pB) {
        pA = pA == nullptr ? headB : pA->next;
        pB = pB == nullptr ? headA : pB->next; // 如果为空 则指向另一个链表的头部
    }
    return pA;
}

/***
 * method 2: 哈希表法
 */
ListNode *getIntersectionNode_hashset(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> nodes_in_A;

    ListNode* currentA = headA;
    // 把A中的元素都插入到哈希表中
    while (currentA != nullptr) {
        nodes_in_A.insert(currentA); // insert方法插入元素
        currentA = currentA->next;
    }

    ListNode* currentB = headB;
    // 遍历B 看哈希表中有没有B的元素
    while (currentB != nullptr) {
        if (nodes_in_A.find(currentB) != nodes_in_A.end()) {
            // 哈希表查找元素：find(key)
            return currentB;
        }
        currentB = currentB->next;
    }
    return nullptr;
}

int main() {
   // 验证函数正确性

    // 创建相交部分
    auto* intersect = new ListNode(8);
    intersect->next = new ListNode(4);

    // 创建链表A
    auto* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = intersect; // 链接到相交部分
    // 创建链表B
    auto* headB = new ListNode(3);
    headB->next = intersect; // 链接到相交部分

    ListNode* result = getIntersectionNode_hashset(headA, headB);

    if (result) {
        cout << "相交节点的值为：" << result->val << endl;
    } else {
        cout << "两个链表不相交" << endl;
    }

    // 释放内存
    delete headA->next->next;
    delete headA->next;
    delete headA;
    delete headB;
    delete intersect->next;

    return 0;
}
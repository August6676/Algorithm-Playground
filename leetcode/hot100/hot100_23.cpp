#include <iostream>
#include <queue>
#include <vector>

#include "ListNode.h"
using namespace std;

class Compare {
public:
    bool operator()(ListNode* a,ListNode* b) {
        return a->val > b->val; // 小顶堆，比较节点的值
    }
};

/*
 * 合并k个升序链表
 * 这里使用优先队列（最小堆）解决
 * leetcode风格的题目 很多要使用复杂一点的数据结构就可以解决 和acwing有点区别
 */
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    priority_queue<ListNode*,vector<ListNode*>,Compare> minHeap;

    // 将所有链表的头节点放入最小堆 这里只放头节点
    for (ListNode* node: lists) {
        if (node)
            minHeap.push(node);
    }

    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;

    while (!minHeap.empty()) {
        ListNode* node = minHeap.top();
        minHeap.pop();

        curr->next = node;
        curr = curr->next;

        if (node->next)
            minHeap.push(node->next);
    }

    return dummy->next;
}

#include <iostream>

#include "TreeNode.h"
using namespace std;


/*
 * 自己做的时候执行了一整遍中序遍历，然后再去排序val再去更改 可以使用两个指针记录的方式简化
 * 但是又涉及到& 也就是都使用同一个指针
 * 还是稍微有点难想
 */
void InorderTraversal(TreeNode* root,TreeNode*& prev,TreeNode*& first,TreeNode*& second) {
    if (root == nullptr) return;
    InorderTraversal(root->left,prev,first,second);

    // 检查是否逆序
    if (prev && root->val < prev->val) {
        if (!first) first = prev;
        second = root;
    }

    prev = root;
    InorderTraversal(root->right,prev,first,second);
}

void recoverTree(TreeNode* root) {
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    InorderTraversal(root,prev,first,second);

    if (first && second) {
        swap(first->val,second->val);
    }
}
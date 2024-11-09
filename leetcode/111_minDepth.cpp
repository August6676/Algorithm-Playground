#include <iostream>
using namespace std;
#include "TreeNode.h"

/*
 * vs https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/ 二叉树的最大深度
 * https://github.com/August6676/Algorithm-Playground/blob/master/leetcode/hot100/hot100_104.cpp
 * 求最小深度 要注意 如果有一边子树为空，也不可以认为是0
 * 自己做的又是多次重复递归 优化后及时止损
 */
int minDepth(TreeNode* root) {
    if (root == nullptr) return 0; // 节点为空
    if (root->left == nullptr && root->right == nullptr) return 1; // 节点为叶子节点

    // 左右子树如果不为空 那么就计算深度 否则就取无穷大
    int leftDepth = root->left ? minDepth(root->left): INT_MAX;
    int rightDepth = root->right ? minDepth(root->right): INT_MAX;

    // 加上自己的1
    return min(leftDepth,rightDepth) + 1;
}
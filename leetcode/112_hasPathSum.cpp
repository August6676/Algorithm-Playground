// 学着使用头文件！！
#include "TreeNode.h"
#include <iostream>
using namespace std;

/*
 * 路径总和Ⅰ
 */
bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;
    // 这里都要求是叶子节点 所以要左右都为nullptr
    if (root->val == targetSum && root->left == nullptr && root->right == nullptr) return true;
    return hasPathSum(root->left,targetSum - root->val) || hasPathSum(root->right,targetSum - root->val);
}
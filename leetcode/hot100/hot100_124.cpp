#include <iostream>
using namespace std;

#include <TreeNode.h>

/*
 * 二叉树的最大直径和这道题非常相似
 */
int ans = INT_MIN; // 最小数字

int maxSum(TreeNode* root) {
    if (root == nullptr) return 0;
    int L = maxSum(root->left);
    int R = maxSum(root->right);
    ans = max(ans,L + R + root->val); // 更细最大值
    return max(max(L,R) + root->val,0); // 左右两支选一支最大的，要么就不传递
}

int maxPathSum(TreeNode* root) {
    maxSum(root);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << "max depth is " << maxPathSum(root) << endl;
}
#include <iostream>

#include "TreeNode.h"
using namespace std;

int maxDepth(TreeNode* root,int& ans) {
    // 使用 int& 表示一个整型的引用。引用是一个别名，允许你通过一个变量来访问另一个变量，而不需要创建副本。
    if (root == nullptr) return 0;

    int leftDepth = maxDepth(root->left,ans);
    int rightDepth = maxDepth(root->right,ans);

    ans = max(leftDepth+rightDepth,ans); // 深度正好是二叉树的直径 比较最大即可

    return max(leftDepth,rightDepth) + 1; // 就是求二叉树的最大深度
}

int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    maxDepth(root,ans);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new  TreeNode(4);
    root->right->right = new  TreeNode(3);

    cout << "二叉树的最大直径为：" << endl;
    cout << diameterOfBinaryTree(root) << endl;
}


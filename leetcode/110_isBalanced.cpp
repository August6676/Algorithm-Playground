#include <iostream>
#include <vector>

#include "TreeNode.h"
using namespace std;


/*
 * 自己做用了深度优先遍历和一个计算节点深度的函数
 * 但是这样其实消耗内存很大
 * 记录一下从底向上递归的方法
 * abs函数取绝对值
 */
int checkBalaced(TreeNode* node) {
    if (!node) return 0;
    int leftDepth = checkBalaced(node->left);
    if (leftDepth == -1) return -1; // 左子树不平衡 直接返回
    int rightDepth = checkBalaced(node->right);
    if (rightDepth == -1) return -1; // 右子树同理
    if (abs(leftDepth - rightDepth) > 1) return -1;
    return max(leftDepth,rightDepth) + 1;
}

bool isBalanced(TreeNode* root) {
    return checkBalaced(root) != -1;
}

/*
 * 我自己的做法 就是时间复杂度接近o(n2)
 */
int countDepth(TreeNode* root, int currentDepth) {
    if (root == nullptr) return currentDepth;
    return max(countDepth(root->left,currentDepth + 1),countDepth(root->right,currentDepth + 1));
}

bool isBalanced2(TreeNode* root) {
    if (root == nullptr) return true;
    if (abs(countDepth(root->left,0) - countDepth(root->right,0)) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

// 构建二叉树
TreeNode* buildTree(const vector<int>& nodes, int index) {
    if (index >= nodes.size() || nodes[index] == -1) return nullptr;
    TreeNode* root = new TreeNode(nodes[index]);
    root->left = buildTree(nodes, 2 * index + 1);
    root->right = buildTree(nodes, 2 * index + 2);
    return root;
}

int main() {
    // 示例 1：平衡二叉树
    vector balancedTreeNodes = {1, 2, 3, 4, 5, 6, 7}; // 完全二叉树
    if (isBalanced(buildTree(balancedTreeNodes,0)))
        cout << "The tree is balanced";
    else cout << "The tree is not balanced.";
    cout << endl;
    // 示例 2：不平衡二叉树
    vector<int> unbalancedTreeNodes = {1, 2, 3, 4, -1, -1, -1, 5}; // 非平衡
    if (isBalanced2(buildTree(unbalancedTreeNodes,0)))
        cout << "The tree is balanced.";
    else cout << "The tree is not balanced";
}
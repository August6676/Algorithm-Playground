#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

/*
 * 思路卡在这里了，深度优先遍历寻找路径，用bool来表示找没找到，深度优先遍历还是得练
 */
bool findPath(TreeNode* root,int target,vector<TreeNode*>& path) {
    if (root == NULL) return false;

    // 这里要放到path里面去，因为有可能在同一个路径上，没有加入节点就会导致找不对
    path.push_back(root);

    if (root->val == target) return true;

    if (findPath(root->left,target,path) || findPath(root->right,target,path)) return true;

    // 没有找到当前节点 回溯
    path.pop_back(); // 移除最后一个节点
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> pathP,pathQ;

    if (!findPath(root,p->val,pathP) || !findPath(root,q->val,pathQ)) return NULL;


    // 找到距离两者最近的父节点
    int i = 0;
    while (i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]) {
        i++;
    }

    // 返回最后一个公共节点
    return pathP[i - 1];
}

int main() {
    // 示例二叉树构建
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // 查找最近公共祖先
    TreeNode* ancestor = lowestCommonAncestor(root, root->left, root->right);
    if (ancestor) {
        cout << "The lowest common ancestor is: " << ancestor->val << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    return 0;
}
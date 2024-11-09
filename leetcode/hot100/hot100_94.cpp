#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#include "TreeNode.h"

/*
 * 法一：递归
 * */

void inorder(TreeNode* root,vector<int>& ans) {
    // 中序遍历左中右
    if (root == nullptr) return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    inorder(root,ans);
    return ans;
}

/*
 * 法二：迭代
 * */
vector<int> inorderTraversal2(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> s;
    // s.push(root);

    while (!s.empty() || root != nullptr) {
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        ans.push_back(root->val);
        root = root->right;
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(8);
    root->right->left->left = new TreeNode(9);

    vector<int> inorder = inorderTraversal2(root);
    cout << "中序遍历的结果为：" << "\n";
    for (int num : inorder) {
        cout << num << " " << endl;
    }
}

#include <iostream>
#include <queue>
#include <vector>

#include "TreeNode.h"
using namespace std;


/*
 * 使用二叉树层次遍历，取出每一层最右侧的数值
 */
vector<int> rightSideView(TreeNode* root) {
    if (root == nullptr) return {};
    vector<int>ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int current_size = q.size();
        for (int i = 0; i < current_size;i++) {
            TreeNode* current = q.front();
            q.pop();
            if (i == current_size - 1) ans.push_back(current->val);
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);

        }
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

    vector<int> ans = rightSideView(root);
    cout << "二叉树右视图的结果为：" << "\n";
    for (int num : ans) {
        cout << num << " " << endl;
    }
}
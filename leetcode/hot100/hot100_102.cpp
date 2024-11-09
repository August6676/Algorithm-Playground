#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#include "TreeNode.h"

vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {}; // 先处理为空的情况
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> result;

    while (!q.empty()) {
        vector<int> currLevel;
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            currLevel.push_back(node->val);

            // 将左右节点加入队列
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(currLevel);
    }
    return result;
}

void printResult(const vector<vector<int>>& result) {
    for (const auto& level: result) {
        for (int val: level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "打印层序遍历结果为：" << endl;
    printResult(levelOrder(root));

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    return 0;
}
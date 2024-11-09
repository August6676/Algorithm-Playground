#include <iostream>
#include <queue>
using namespace std;
#include "TreeNode.h"

int maxDepth_BFS(TreeNode* root) {
    if (root == nullptr) return 0;
    queue<pair<TreeNode*,int>> q;
    q.push({root,1});
    int maxdepth = 0;

    while (!q.empty()) {
        auto[node,depth] = q.front(); // 获取当前节点和深度
        q.pop();
        // maxdepth = depth > maxdepth ? depth:maxdepth;
        maxdepth = max(depth,maxdepth);

        if (node->left) q.push({node->left,depth + 1});
        if (node->right) q.push({node->right,depth + 1});
    }

    return maxdepth;
}

int maxDepth_DFS(TreeNode* root) {
    if (!root) return 0;
    return max(maxDepth_DFS(root->left),maxDepth_DFS(root->right)) + 1;
}

int main() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right  = new TreeNode(7);
    cout << "二叉树的深度为：" << endl;
    cout << "使用深度优先遍历：" << maxDepth_DFS(root) << endl;
    cout << "使用广度优先遍历：" << maxDepth_BFS(root);
}
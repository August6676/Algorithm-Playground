#include <iostream>
#include <unordered_map>

#include "TreeNode.h"
using namespace std;


int count = 0;
/*
 * 路径总和Ⅲ
 * 深度优先搜索
 */
void dfs(TreeNode* root, long long targetSum) {
    if (root == nullptr) return;

    if (root->val == targetSum) count++;

    dfs(root->left,targetSum - root->val);
    dfs(root->right,targetSum - root->val);
}

int pathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return 0;

    dfs(root,targetSum);
    pathSum(root->left,targetSum);
    pathSum(root->right,targetSum);

    return count;
}


/*
 * 第2种做法，借助前缀和
 */
unordered_map<long long,int> prefixSums;
void dfs(TreeNode* node,long long currentSum,int targetSum) {
    if (node == nullptr) return;

    currentSum += node->val;
    if (prefixSums.count(currentSum - targetSum)) count += prefixSums.count(currentSum - targetSum);

    prefixSums[currentSum]++;

    dfs(node->left,currentSum,targetSum);
    dfs(node->right,currentSum,targetSum);

    // 回溯时将当前路径前缀和从哈希表种移除
    prefixSums[currentSum]--;

}
int pathSum2(TreeNode* root,int targetSum) {
    if (root == nullptr) return 0;
    // 路径和为0的前缀出现了一次
    prefixSums[0] = 1;

    dfs(root,0,targetSum);
    return count;
}
int main() {
    // 构建二叉树： 10, 5, -3, 3, 2, NULL, 11, 3, -2, NULL, 1
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int targetSum = 8;
    int result = pathSum2(root, targetSum);

    cout << "Number of paths that sum to " << targetSum << ": " << result << endl;

    return 0;
}
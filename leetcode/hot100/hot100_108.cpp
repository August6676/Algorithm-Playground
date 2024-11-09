#include <iostream>
#include <vector>
using namespace std;
#include "TreeNode.h"

TreeNode* buildTree(vector<int>& nums,int left,int right) {
    if (left > right) return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = buildTree(nums,left,mid - 1);
    node->right = buildTree(nums,mid + 1,right);
    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildTree(nums,0,nums.size() - 1);
}

void inorder(TreeNode* root,vector<int>& ans) {
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

int main () {
    vector<int> nums = {1,2,3,4,5,6,7};
    TreeNode* root = sortedArrayToBST(nums);
    vector<int> ans = inorderTraversal(root);
    for (int num: ans) {
        cout << num << " ";
    }
}


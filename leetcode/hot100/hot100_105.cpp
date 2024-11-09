#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#include "TreeNode.h"
/*
 * 两遍AC，也算是使用哈希表做出来了，但是占用空间太多，在这里进行优化
 * 这里的 preorder_index 要按照引用传递
 * 没明白哇
 * 当你在构建左子树时，preorder_index 会指向左子树的根节点，然后递增。
 * 当递归返回到父节点并开始构建右子树时，preorder_index 会继续递增，指向右子树的根节点。
 */
TreeNode* buildSubTree(vector<int>& preorder,vector<int>& inorder,unordered_map<int,int>& inorder_map,int& preorder_index,int in_start,int in_end) {
    // 递归结束条件：
    if (in_start > in_end) return nullptr;

    // 获取当前节点值
    int root_val = preorder[preorder_index];
    preorder_index++;
    TreeNode* root = new TreeNode(root_val);

    // 获取根节点在inorder中的位置
    int root_inorder_index = inorder_map[root_val];

    root->left = buildSubTree(preorder,inorder,inorder_map,preorder_index,in_start,root_inorder_index - 1);
    root->right = buildSubTree(preorder,inorder,inorder_map,preorder_index,root_inorder_index + 1,in_end);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // 先使用哈希表存起来
    unordered_map<int,int> inorder_map;
    for (int i = 0; i < inorder.size(); i++) {
        inorder_map[inorder[i]] = i;
    }
    int preorder_index = 0;
    return buildSubTree(preorder,inorder,inorder_map,preorder_index,0,inorder.size() - 1);
}

// 前序遍历输出树的节点
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " "; // 先打印根节点
    preorderTraversal(root->left); // 遍历左子树
    preorderTraversal(root->right); // 遍历右子树
}

int main() {
    // 定义 preorder 和 inorder 数组
    vector preorder = {3, 9, 20, 15, 7};
    vector inorder = {9, 3, 15, 20, 7};

    // 构建树
    TreeNode* root = buildTree(preorder, inorder);

    // 输出树的前序遍历
    cout << "前序遍历结果: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
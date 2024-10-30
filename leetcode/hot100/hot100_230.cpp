#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right): val(x),left(left),right(right) {}
};


void inorder(TreeNode* root,vector<int>& ans) {
    if (root == nullptr) return;

    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int>ans;
    inorder(root,ans);
    return  ans;
}

/*
 * 不求上进，我又来用中序遍历二叉树解决了QAQ
 */
int kthSmallest(TreeNode* root, int k) {
    vector<int> ans;
    ans = inorderTraversal(root);
    return ans[k - 1];
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);

    cout << "请输入整数（1-5）：";
    int k;
    cin >> k;
    cout << "第" << k << "小的节点val为：" << kthSmallest(root,k);
}

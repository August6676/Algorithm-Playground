#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right): val(x),left(left),right(right) {}
};
/*
 * 中序遍历
 */
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

/*
 * 借用中序遍历来判断是否为二叉搜索树
 */
bool isValidBST(TreeNode* root) {
    vector<int> ans;
    ans = inorderTraversal(root);
    for (int i = 0; i < ans.size() - 1; ++i) {
        if (ans[i] >= ans[i - 1]) return false;
    }
    return true;
}

int main() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(8);
    root->right->left->left = new TreeNode(9);

    vector<int> ans = inorderTraversal(root);
    cout << "中序遍历结果为：";
    for (int num: ans) {
        cout << num << " ";
    }
    bool isBST = isValidBST(root);
    if (isBST) cout << "是二叉搜索树";
    else cout << "不是二叉搜索树";
}



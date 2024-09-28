#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x),left(left),right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;

    swap(root->left,root->right); // 使用swap函数直接交换

    invertTree(root->left);
    invertTree(root->right);

    return root;
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

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new  TreeNode(6);
    root->right->right = new  TreeNode(9);

    cout << "翻转之前的二叉树中序遍历结果为" << endl;
    vector<int> ans = inorderTraversal(root);
    for (int num: ans) {
        cout << num << " ";
    }
    cout << " " << "反转之后的二叉树中序遍历结果为" << endl;
    vector<int> res = inorderTraversal(invertTree(root));
    for (int num : res) {
        cout << num << " ";
    }
}

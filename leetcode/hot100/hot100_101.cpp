#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right): val(x),left(left),right(right) {}
};

bool isSymmetric(TreeNode* left,TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (left == nullptr || right == nullptr) return false;
    return (left->val == right->val) && isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
}

bool isSymmetric(TreeNode* root) {
    return isSymmetric(root,root);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new  TreeNode(4);
    root->right->right = new  TreeNode(3);

    bool flag = isSymmetric(root);
    if (flag) cout << "是对称树" << endl;
    else cout << "不是对称树" << endl;
}
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
 * 使用后序遍历的思路
 * 因为链表要是前序的顺序
 * 后序遍历中 把中间节点的左子树放到右边吗 右子树接到最后
 * 当然也可以使用笨方法vector前序遍历，然后再改节点顺序
 */
void flatten(TreeNode* root) {
    if (!root) return;

    flatten(root->left);
    flatten(root->right);

    TreeNode* tempRight = root->right;
    root->right = root->left;
    root->left = nullptr;

    while (root->right) {
        root = root->right;
    }
    root->right = tempRight;
}

// 函数用于打印展平后的链表
void printFlattenedTree(TreeNode* root) {
    while (root) {
        std::cout << root->val << " ";
        root = root->right;
    }
    std::cout << std::endl;
}

int main() {
    // 构建一个示例二叉树
    //       1
    //      / \
    //     2   5
    //    / \   \
    //   3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flatten(root);
    printFlattenedTree(root);

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;
}
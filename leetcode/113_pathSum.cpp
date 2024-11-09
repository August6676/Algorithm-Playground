#include "TreeNode.h"
using namespace std;
#include <vector>

/*
 * 路经总和Ⅱ
 */
vector<vector<int>> path;
void findPath(TreeNode* root,int targetSum,vector<int> current) {
    if (root == nullptr) return;
    if (root->val == targetSum && root->left == nullptr && root->right == nullptr) {
        current.push_back(root->val);
        path.push_back(current);
        return;
    }
    current.push_back(root->val);
    findPath(root->left,targetSum - root->val,current);
    findPath(root->right,targetSum - root->val,current);
    // 执行回溯
    current.pop_back();
}


vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int>current;
    findPath(root,targetSum,current);
    return path;
}




#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used, vector<vector<int>>& result) {
    // 结束条件：当前排列的长度等于数组的长度
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }

    // 遍历所有可能的数字
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue; // 当前数字已经使用过 则跳过
        path.push_back(nums[i]);
        used[i] = true;

        // 递归调用
        backtrack(nums,path,used,result);

        // 回溯
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result; // 最终的全排列
    vector<int> path; // 存储当前的全排列
    vector<bool> used(nums.size(),false); // 记录某个数字是否被使用

    backtrack(nums,path,used,result);
    return result;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = permute(nums);

    for (vector<int> res: result) {
        for (int num: res) {
            cout << num << " ";
        }
        cout << endl;
    }
}
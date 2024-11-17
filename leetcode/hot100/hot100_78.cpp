#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<int>>& result,vector<int>& nums,vector<int>& path,int length,int current) {
    if (path.size() == length) {
        result.push_back(path);
        return;
    }

    for (int i = current; i < nums.size();i++) {
        path.push_back(nums[i]);

        backtrack(result,nums,path,length, i + 1);

        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;

    for (int i = 0; i <= nums.size(); i++) {
        backtrack(result,nums,path,i,0);
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = subsets(nums);

    for (vector<int> ans: result) {
        cout << endl;
        for (int num: ans) {
            cout << num << " ";
        }
    }
}
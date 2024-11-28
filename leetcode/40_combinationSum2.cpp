#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<int>>& result,vector<int>& current,vector<int>& candidates,int target,int index,int currentSum) {
    if (currentSum == target) {
        result.push_back(current);
        return;
    }
    for (int i = index; i < candidates.size();i++) {
        if (i > index && candidates[i] == candidates[i - 1]) continue; // 去重
        if (currentSum > target) break; // 剪枝
        current.push_back(candidates[i]);
        backtrack(result,current,candidates,target,i + 1,currentSum + candidates[i]);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    sort(candidates.begin(), candidates.end()); // 排序语句 相同的元素都聚集在一起
    backtrack(result,current,candidates,target,0,0);
    return result;
}

int main() {
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    vector<vector<int>> result = combinationSum2(candidates,target);
    for (const auto& vec:result) {
        cout << endl;
        for (const auto& v: vec) {
            cout << v << " ";
        }
    }
}
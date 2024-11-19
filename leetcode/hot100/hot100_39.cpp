#include <iostream>
#include <vector>
using namespace std;

/*
 * 回溯法防止重复 往往多加一个index 记录位置
 */
void backtrack(vector<vector<int>>& result,vector<int>& current,vector<int>& candidates,int index,int currentSum,int target) {
    if (currentSum == target) {
        result.push_back(current);
        return;
    }
    if (currentSum > target) return;

    for (int i = index; i < candidates.size();i++) {
        current.push_back(candidates[i]);
        backtrack(result,current,candidates,i,currentSum + candidates[i],target);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> current;
    vector<vector<int>> result;
    backtrack(result,current,candidates,0,0,target);
    return result;
}

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates,target);

    for (const vector<int>& current : result) {
        cout << endl;
        for (const auto& num: current) {
            cout << num << " ";
        }
    }
}
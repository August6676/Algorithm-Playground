#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 自己也算是两边过，现在来简化代码，把一个不必要的循环合并到一起去
bool containsNearbyDuplicate(vector<int>& nums,int k) {
    unordered_map<int,int> numToindex;

    for (int i = 0; i < nums.size(); i++) {
        if (numToindex.count(nums[i])) {
            if (i - numToindex[nums[i]] <= k) return true;
        }
        numToindex[nums[i]] = k; // 更新哈希表
        if (i > k) numToindex.erase(nums[i - k]); // 妙在这里，逐渐消除范围之外的元素 也不用考虑过多的情况
    }

    return false;
}

int main() {
    vector nums = {1,2,3,1};
    int k = 3;
    if (containsNearbyDuplicate(nums,k)) cout << "数组中存在重复元素";
    else cout << "数组中不存在重复元素";
}

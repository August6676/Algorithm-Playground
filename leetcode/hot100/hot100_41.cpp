#include <iostream>
#include <vector>
using namespace std;
/*
 * 原地哈希 用下标和和负数来记录哪些值出现过
 */
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] <= 0 || nums[i] > n) nums[i] = n + 1;
    }

    for (int i = 0; i < n; i++) {
        int num = abs(nums[i]);
        if (num <= n) nums[num - 1] = -abs(nums[num - 1]);
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) return i + 1;
    }

    // 都出现了之后
    return n + 1;
}

int main() {
    vector<int> nums = {1,2,0};
    cout << "缺失的第一个正数为：" << firstMissingPositive(nums);
}
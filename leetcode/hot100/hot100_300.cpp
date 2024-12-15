#include <iostream>
#include <vector>
using namespace std;
/*
 * 也算是自己想明白了动态规划！
 * 其实只需要找到状态转移方程就好！
 * 自己在做的时候maxSub多跑了一次循环，其实可以同步记录！
 */
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1); // 表示到该数的最大长度
    int maxSub = 1;

    for (int i = 0; i < n; i++) {
        int currentSub = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                currentSub = max(currentSub,dp[j] + 1);
        }
        dp[i] = currentSub;
        maxSub = max(maxSub,currentSub);
    }
    return maxSub;
}

int main() {
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    cout << "最长严格递增子序列的长度为" << lengthOfLIS(nums);
}
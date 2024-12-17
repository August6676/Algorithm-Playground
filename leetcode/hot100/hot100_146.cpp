#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

/*
 * 非常妙的动态规划的思想
 * dp[j] = dp[j] || dp[j - num]
 */
bool canPartition(vector<int>& nums) {
    // 累积函数 计算一个数组所有元素的和
    int numSum = accumulate(nums.begin(), nums.end(),0);

    if (numSum % 2 != 0) return false; // 排除不可能

    int target = numSum / 2;
    vector<bool> dp(target + 1,false);
    dp[0] = true; // 和为0的情况

    for (int num : nums) {
        // 从后向前更新dp数组
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[target];
}

int main() {
    vector<int> nums = {1,5,11,5};
    if (canPartition(nums)) cout << "可以分割成两个和相等的子集";
    else cout << "不可以分割成两个和相等的子集";
}
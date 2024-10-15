#include <iostream>
#include <vector>
using namespace std;

/*
 * 贪心算法：Kadane's Algorithm
 * 本来想用双指针 但是这样复杂度反而更高 减去previousSum 其实不如比较current和previous谁最大取谁
 * */
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0],currentSum = nums[0];
    for (int i = 1; i < nums.size();i++) {
        currentSum = max(nums[i],currentSum + nums[i]); // core
        maxSum = max(currentSum,maxSum);
    }
    return maxSum;
}

int main() {
    vector nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "连续子数组最大和为：" << maxSubArray(nums);
}
#include <iostream>
#include <vector>
using namespace std;

// 自己也是一遍写出来 这里记录下优化和简化后的代码 时间复杂度 O(n)
int minSubArrayLen(int target,vector<int>& nums) {
    int currentSum = 0;
    int left = 0;
    int minLength = nums.size() + 1; // 初始化最大的长度

    for (int right = 0; right < nums.size(); right++) {
        currentSum += nums[right];

        // 缩小窗口
        while (currentSum >= target) {
            // 先更新最短长度
            minLength = min(minLength,right - left + 1); // 不需要维护一个currentLength
            currentSum -= nums[left];
            left++;
        }
    }
    return minLength == nums.size() + 1 ? 0 : minLength;
}

int main() {
    int target = 7;
    vector nums = {2,3,1,2,4,3};
    if (minSubArrayLen(target,nums) == 0) cout << "不存在和为" << target << "的子数组";
    else cout << "和为 " << target << " 的子数组长度最小为 " << minSubArrayLen(target,nums);
}
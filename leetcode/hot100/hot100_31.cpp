#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 返回下一个字典序 是一个技巧类的题目
 * 不过STL中自带函数next_permutation()可以直接使用
 */
void nextPermutation1(vector<int>& nums) {
    next_permutation(nums.begin(),nums.end());
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size(),i = n - 1,j = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) // 找到第一个逆序点
        i--;
    if (i >= 0) {
        // 存在逆序点
        while (nums[i] <= nums[j]) // 把逆序点和最后边大于这个数的值交换
            j--;
        swap(nums[i],nums[j]); // 交换两个数
    }

    reverse(nums.begin() + i + 1,nums.end()); // 右侧重新反转
}

int main() {
    vector<int> nums = {1,2,3};
    nextPermutation(nums);
    for (int num : nums)
        cout << num << " ";
}
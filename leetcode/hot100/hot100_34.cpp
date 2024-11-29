#include <vector>
#include <iostream>
using namespace std;
/*
 * 其实就是稍加变形的二分查找
 */
vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1,-1};
    int left = 0,right = nums.size() - 1,mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            while (nums[left] < target) left++;
            while (nums[right] > target) right--;
            return {left,right};
        }
        if (nums[mid] > target) right = mid--;
        else if (nums[mid] < target) left = mid++;
    }
    return {-1,-1};
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = searchRange(nums,target);
    for (const auto& num: result) {
        cout << num << " ";
    }
}
#include <vector>
#include <iostream>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0,right = nums.size() - 1;

    // 1.找到旋转点
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) left = mid + 1; // 旋转点在右侧
        else right = mid; // 有可能是旋转点 也有可能在左侧
    }

    // 旋转点
    int pivot = left;
    left = 0,right = nums.size() - 1;

    // 确定搜索范围
    if (target >= nums[pivot] && target <= nums[right]) {
        left = pivot; // 在右侧
    } else right = pivot - 1; // 在左侧

    // 进行标准二分查找
    while (left <= right) {
        int mid = left + (right- left) / 2;
        if (nums[mid] == target) return mid;
        if (target > nums[mid]) left = mid + 1;
        else right = mid - 1; // 在这里不能随便用++ --！ mid++ 是先赋值 再++
    }
    return -1; // 表示未找到
}

int main() {
    vector<int> nums1 = {4,5,6,7,0,1,2};
    int target1 = 0; // 输出: 4
    cout << search(nums1,target1) << endl;

    vector<int> nums2 = {4,5,6,7,0,1,2};
    int target2 = 3; // 输出: -1
    cout << search(nums2,target2) << endl;
}
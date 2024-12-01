#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
 * vs hot100_33 找到旋转点 这一题也一样
 * 当数组分两段有序的时候仍然可以采用这种二分查找
 */
int findMin(vector<int>& nums) {
    // 不许这样做
    /*
    sort(nums.begin(), nums.end());
    return nums[0];
    */
    // 正经做法
    int front = 0, end = nums.size() - 1;
    while (front < end) {
        int mid = front + (end - front) / 2;
        if (nums[mid] < nums[end]) end = mid;
        else front = mid + 1;
    }
    return nums[front];
}

int main() {
    vector nums = {4,5,6,7,0,1,2};
    cout << "最小的元素为：" << findMin(nums);
}
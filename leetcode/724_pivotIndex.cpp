#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

int pivotIndex(vector<int>& nums) {
    // 前缀和的思想？
    int total = accumulate(nums.begin(), nums.end(),0);
    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (2 * leftSum + nums[i] == total) return i; // 数学推算出来
        leftSum += nums[i];
    }
    return -1;
}

int main() {
    vector nums = {1, 7, 3, 6, 5, 6};
    cout << "数组的中心下标为：" << pivotIndex(nums);
}
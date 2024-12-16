#include <iostream>
#include <vector>
using namespace std;

/*
 * 还是动态规划，但是要把时间复杂度降到o(n)
 * 维护最大值和最小值一次遍历就可以
 */
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (int i = 1; i < n; i++) {
        int current = nums[i];

        if (current < 0)
            swap(maxProd,minProd);

        maxProd = max(maxProd * current,current);
        minProd = min(minProd * current,current);

        result = max(result,maxProd);
    }
    return result;
}

int main() {
    vector<int> nums = {1,0,-5,2,3,-8,-9};
    cout << "最大子数组乘积为：" << maxProduct(nums);
}
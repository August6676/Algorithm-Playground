#include <iostream>
#include <vector>
using namespace std;

/*
 * 接雨水 使用双指针的办法解决
 * 当前柱子能接的雨水量取决于其高度和其两侧最大高度的最小值之间的差值
 */
int trap(vector<int>& height) {
    int left = 0,right = height.size() - 1;
    int left_max = 0,right_max = 0;
    int water = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] < left_max) water += left_max - height[left];
            else left_max = height[left];
            left++;
        } else {
            if (height[right] < right_max) water += right_max - height[right];
            else right_max = height[right];
            right--;
        }
    }

    return water;
}


int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "雨水的数量为 " << trap(height) << endl;
}
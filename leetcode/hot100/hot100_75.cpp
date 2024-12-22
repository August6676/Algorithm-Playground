#include <iostream>
#include <vector>
using namespace std;

/*
 * 荷兰国旗问题
 * 0 1 2用三个指针代表
 * 和0交换的时候current++ 是1不用处理 current也是++
 * 但是如果是2 那么交换过来的元素不知道是什么 还需再处理 不需要++
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int front = 0;
        int end = nums.size() - 1;
        int current = 0;
        while (current <= end) {
            if (nums[current] == 0) {
                swap(nums[current],nums[front]);
                current++;
                front++;
            } else if (nums[current] == 2) {
                swap(nums[current],nums[end]);
                end--;
            } else current++;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,0,2,1,1,0};
    solution.sortColors(nums);

    for (int num: nums) {
        cout << num << " ";
    }
}
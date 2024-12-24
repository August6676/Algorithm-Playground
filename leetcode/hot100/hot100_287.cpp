#include <vector>
#include <iostream>
using namespace std;

int findDuplicate(vector<int>& nums) {
    // 可以考虑看成快慢指针，nums[i] -> nums[nums[i]]
    // 其实还是floyd判圈算法
    int slow = nums[0], fast = nums[0];
    // 快指针两步 慢指针一步
    // 改成 while 也可以，但需要手动在循环前先移动一次指针 do while 可以从同一个起点
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    // 从起点开始 都走一步 相遇点就是重复点
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    vector<int> nums = {1,3,4,2,2};
    cout << "重复的数字为：" << findDuplicate(nums);
}
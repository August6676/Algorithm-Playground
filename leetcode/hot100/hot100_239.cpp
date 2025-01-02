#include <deque>
#include <iostream>
#include <vector>
using namespace std;

/*
 * 双端队列
 * 左右两边都可以删除
 * hard 滑动窗口
 */
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty() || k == 0) return {};
    vector<int> result(nums.size() - k + 1);
    deque<int> dq;
    // 首轮元素
    for (int i = 0; i < k;i++) {
        while (!dq.empty() && dq.back() < nums[i])
            dq.pop_back();
        dq.push_back(nums[i]);
    }
    result[0] = dq.front(); // 头部元素
    for (int i = k; i < nums.size();i++) {
        if (!dq.empty() && dq.front() == nums[i - k]) // 如果上个窗口的第一个元素是最大值 pop back
            dq.pop_front();
        while (!dq.empty() && dq.back() < nums[i]) // 比nums[i]小的，还在左边 不可能直接删去
            dq.pop_back();
        dq.push_back(nums[i]);
        result[i - k + 1] = dq.front();
    }
    return result;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums,k);
    for (int re: result)
        cout << re << " ";
}
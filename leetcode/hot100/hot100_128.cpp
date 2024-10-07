#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 判断最长连续字符串 找起点元素 再从这个元素之后找终点元素
int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    int currentStreak = 0,longestStreak = 0;
    int currentNum;
    unordered_set<int>numSet(nums.begin(),nums.end()); // 用哈希表存储数组的元素

    for (int num:nums) {
        if (!numSet.count(num - 1)) {
            currentNum = num;
            currentStreak = 1;

            while (numSet.count(currentNum + 1)) {
                currentNum ++;
                currentStreak ++;
            }
            longestStreak = max(longestStreak,currentStreak);
        }
    }
    return longestStreak;
}

int main() {
    vector<int> nums = {1,2,3,3,4,5,7,8,0};
    cout << "数组中最长连续序列的长度为：";
    cout << longestConsecutive(nums);
}
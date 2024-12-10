#include <vector>
#include <iostream>
using namespace std;

/*
 * 这是跳跃游戏Ⅱ vs跳跃游戏Ⅰ
 * 及时更新边界 仍然使用贪心算法
 */
int jump(vector<int>& nums) {
  int step = 0; // 当前步数
  int farthest = 0; // 当前最远距离
  int currentIndex = 0; // 当前位置

  for (int i = 0; i < nums.size() - 1; i++) {
   farthest = max(farthest,nums[i] + i);

   if (currentIndex == i) {
    step++;
    currentIndex = farthest;
    if (currentIndex >= nums.size() - 1) break;
   }
 }

  return step;
}

int main() {
 vector<vector<int>> testCases = {
  {2, 3, 1, 1, 4}, // 最少跳跃次数：2（0 -> 1 -> 4）
  {2, 3, 0, 1, 4}, // 最少跳跃次数：2（0 -> 1 -> 4）
  {1, 2, 3},       // 最少跳跃次数：2（0 -> 1 -> 2）
  {1, 1, 1, 1},    // 最少跳跃次数：3
  {5, 4, 3, 2, 1}, // 最少跳跃次数：1（0 -> 终点）
};

 for (auto& nums : testCases) {
  cout << "Steps: " << jump(nums) << endl;
 }
}

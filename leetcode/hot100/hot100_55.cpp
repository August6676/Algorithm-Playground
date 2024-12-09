#include <iostream>
#include <vector>
using namespace std;

/*
 * 本来采用倒序贪心 但是这样做潜在时间复杂度比较高
 * 改为正序贪心
 */
bool canJump(vector<int>& nums) {
   int maxReach = 0;
    for (int i = 0; i < nums.size();i++) {
        if (i > maxReach) return false; // 当前位置不可达
        maxReach = max(maxReach,nums[i] + i); // 可达 更新边界 贪心往往就是这一步
        if (maxReach >= nums.size() - 1) return true; // 及时return
    }

    return false;
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    if (canJump(nums)) cout << "能够到达最后一个下标";
    else cout << "无法到达";
}
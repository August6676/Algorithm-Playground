#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    // 先排序
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0;i < nums.size();i++) {
        if (i >0 && nums[i] == nums[i -1]) continue; // 避免重复

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum > 0) right--;
            else if (sum < 0) left++;
            else {
                ans.push_back({nums[i],nums[left],nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++; // 避免重复
                while (left < right && nums[right] == nums[right - 1]) right--; // 避免重复
                left ++;
                right --;
            }
        }
    }
    return ans;
}

int main() {
    vector nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(nums);
    cout << "和为0的元素为：" << endl;
    for (const vector<int>& res: ans) {
        // const关键字：确保循环体内无法修改 res 的内容；&：使用引用 (&) 可以避免拷贝整个 vector，提高性能
        for (int num : res) {
            cout << num << " ";
        }
        cout << endl;
    }
}
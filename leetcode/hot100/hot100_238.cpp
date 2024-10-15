#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> prefix(nums.size(),1); // 存储前面的 注意 初始化的时候需要是1
    vector<int> endfix(nums.size(),1); // 存储后面的

    for (int i = 1; i < nums.size();i++) {
        prefix[i] = prefix[i -1] * nums[i - 1];
    }

    for (int i = nums.size() - 2; i >= 0; i--) {
        endfix[i] = nums[i + 1] * endfix[i + 1];
    }

    vector<int> ans(nums.size(),1);
    for (int i = 0; i < nums.size(); i++) {
        ans[i] = prefix[i] * endfix[i];
    }
    return ans;
}

int main() {
    vector nums = {-1,1,0,-3,3};
    vector<int> ans = productExceptSelf(nums);
    for (int num: ans) {
        cout << num << " ";
    }
}

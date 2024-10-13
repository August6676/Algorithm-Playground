#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * 前缀和
 * */
int subarraySum(vector<int>& nums,int k) {
    int ans = 0,currentSum = 0;
    unordered_map<int,int> prefix;
    prefix[0] = 1; // 注意这个0 代表了到自己的情况 其实也是要有的！
    for (int i = 0; i < nums.size();i++) {
        currentSum += nums[i];
        // 因为是从头到这个位置 也就是哪怕和一样 其实子数组的长度是不一样的 所以这里没有重复计算！
        if (prefix.count(currentSum - k)) ans += prefix[currentSum - k];
        // 假设 currentSum - k 正好等于 currentSum，如果先增加了 prefix[currentSum]，这时会导致当前的 currentSum 自己也被当作满足条件的前缀和
        // 主要是k = 0 的特殊情况
        prefix[currentSum] ++;
    }
    return ans;
}

int main() {
    vector nums = {1,1,1,3,5};
    int k = 2;
    cout << "和为"<< k << "的子数组有" << subarraySum(nums,k) << "个";
}
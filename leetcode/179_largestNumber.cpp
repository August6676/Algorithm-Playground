#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/*
 * 看到大佬题解 用lambda表达式几行代码kuku解决了
 * 哦买噶
 */
string largestNumber(vector<int>& nums) {
    // 自定义排序规则
    sort(nums.begin(), nums.end(),[](int x,int y) {
        return to_string(x) + to_string(y) > to_string(y) + to_string(x);
    });
    // 特殊情况
    if (nums[0] == 0) return"0";
    string result;
    for (int num:nums) {
        // 注意这里 字符串拼接 应该用＋
        result += to_string(num);
    }
    return result;
}

int main() {
    vector<int> nums = {3,30,34,5,9};
    cout << "最大数为：" << largestNumber(nums) << endl;
}
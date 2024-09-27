#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> num_to_index; // 哈希表语法：unordered_map<key_type, value_type>
    for(int i=0; i<nums.size(); i++) {
        if (num_to_index.find(target-nums[i]) != num_to_index.end()) { // 哈希表查找元素：find(key)
            return {i,num_to_index[target-nums[i]]}; // 用大括号包裹起来的返回值，表示返回的是一个数组
        }
        num_to_index[nums[i]] = i; // 键是nums[i]，值是i，这样可以查找到对应下标且不会重复
    }
    return {};
}

int main() {
    int n,target;

    // 获取输入
    cout << "请输入数组的长度";
    cin >> n;

    vector<int> nums(n);
    cout << "请输入数组的元素（用空格分开）";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "请输入目标值";
    cin >> target;

    vector<int> result = twoSum(nums,target);

    // 打印结果
    if (!result.empty()) {
        cout << "和为target的两个整数下标为" << result[0] << "和" << result[1] << endl;
    } else {
        cout << "没有找到和为atrget的两个整数" << endl;
    }

    return 0;
}
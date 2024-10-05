#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * method1:位运算 如果和非0非本身元素进行运算 那么结果为换算成二进制的如下规则
 * */
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num; // 位运算和自己是0 和0为本身 最终剩下的那个就是答案！
    }
    return result;
}

/*
 * method2:哈希表（空间复杂度太高）
 * */
int singleNumber2(vector<int>& nums) {
    unordered_map<int,int> record;

    for (int num:nums) {
        record[num]++;
    }

    for (const auto& pair: record) {
        if (pair.second == 1) return pair.first;
    }
    return 0;
}

int main() {
    cout << "请输入数组的长度：";
    int length;
    cin >> length;
    cout << "请输入数组的元素（空格分开）" << endl;
    vector<int> nums;
    int num;
    for (int i = 0;i < length;i++) {
        cin >> num;
        nums.push_back(num);
    }
    cout << "1.只出现一次的元素是：" << singleNumber(nums) << endl;
    cout << "2.只出现一次的元素是：" << singleNumber2(nums) << endl;
}

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    // 使用双指针 左指针指向已经处理好的序列尾部，右指针指向待处理的序列头部
    // 从left开始到right的前一个元素是0
    int n = nums.size();
    int left = 0;
    int right = 0;
    while (right < n) {
        // 如果right遇到非零元素，则将其与left指向的元素交换，并将left右移一位
        if (nums[right]) {
            swap(nums[left],nums[right]);
            left ++;
        }
        right ++;
    }

}

int main () {
    int n;
    cout << "请输入数组的长度：";
    cin >> n;
    vector<int> nums(n);
    cout << "请输入数组的元素（用空格分开）：";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "原始数组：";
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    moveZeroes(nums);
    cout << "\n移动0到数组头部后的数组：";
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
}
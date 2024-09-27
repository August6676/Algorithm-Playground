#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int left = 1,right = 1;
    while (right < n) {
        if (nums[right] != nums[right-1]) { // 说明元素不一样，那么赋值给left指向的元素 left会向右移动一格
            nums[left] = nums[right];
            left ++;
        }
        right ++;
    }
    return left;
}

int main() {
    int n ;
    cout << "请输入数组的长度：";
    cin >> n;
    vector<int> nums(n);
    cout << "请输入数组的元素（用空格分开）：";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int m = removeDuplicates(nums);
    cout << "去重后数组的长度：" << m << endl;
    cout << "去重后数组的元素：";
    for (int i = 0; i < m; ++i) {
        cout << nums[i] << " ";
    }
}
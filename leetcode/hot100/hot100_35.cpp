#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums,int target) {
    int front = 0;
    int end = nums.size() - 1;
    int mid = (front + end) /2;

    while (front < end) {
        if (nums[mid] == target) return mid;

        if (nums[mid] > target) end =  mid - 1;
        else if (nums[mid] < target) front = mid + 1;
        mid = (front + end) / 2;
    }
    if (nums[mid] < target) return mid + 1; // 如果target比当前的数大 要添加到他的后面
    else return mid;
}

int main() {
    int size,target;

    cout << "请输入数组的长度：";
    cin >> size;
    cout << "请输入数组中的元素（空格分开）：";
    vector<int> nums(size); // 这里要初始化大小，后面才能用nums[i]的方法赋值
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    cout << "请输入插入的目标数值";
    cin >> target;
    int palce = searchInsert(nums,target);
    cout << "应该插入的目标位置是：" << palce << endl;

}
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Boyer-Moore 投票算法
 * */
int majorityElement(vector<int>& nums) {
    int candidate;
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count++;
        } else if (candidate != num) count--;
        else if (candidate == num)count--;
    }
    return candidate; // 因为确定一定有一半多的元素一样 所以不需要验证
}

/*
 *  哈希表
 * */
int majorityElement2(vector<int>& nums) {
    int threshhold = nums.size() / 2;
    unordered_map<int,int> count;

    for (int num : nums) {
        count[num] ++;
        if (count[num] > threshhold) return num;
    }
    return 0;
}

int main() {
    vector nums1= {2,2,1,1,1,2,2};
    vector nums2 = {3,2,3};
    cout << "1.大于数组一半长度的元素为："<< majorityElement(nums2) <<endl;
    cout << "2.大于数组一半长度的元素为："<< majorityElement2(nums2) <<endl;
}
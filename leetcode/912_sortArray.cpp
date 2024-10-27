#include <vector>
#include <iostream>
using namespace std;
/*
 *  两个有序数组的合并
 * */
vector<int> mergeArrays(vector<int>& nums1,vector<int>& nums2) {
    vector<int>result;
    int point1 = 0,point2 = 0;
    while (point1 < nums1.size() && point2 < nums2.size()) {
        if (nums1[point1] < nums2[point2]) {
            result.push_back(nums1[point1]);
            point1++;
        }else {
            result.push_back(nums2[point2]);
            point2++;
        }
    }
    for (int i = point1; i < nums1.size();i++) {
        result.push_back(nums1[i]);
    }

    for (int i = point2; i < nums2.size();i++) {
        result.push_back(nums2[i]);
    }

    return result;
}

/*
 *  归并排序主代码，注意left和right要赋值
 * */
vector<int> sortArray(vector<int>& nums) {
    if (nums.empty() || nums.size() == 1) return nums;

    int mid = nums.size() / 2;
    vector left(nums.begin(),nums.begin() + mid);
    vector right(nums.begin() + mid,nums.end());
    // 这里忘记了赋值，QAQ
    left = sortArray(left);
    right = sortArray(right);
    return  mergeArrays(left,right);
}

void printVector(vector<int>& nums) {
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector nums = {19,8,5,3,0,1,54,6};
    cout << "原来的数组为：";
    printVector(nums);
    nums = sortArray(nums);
    cout << "归并排序后的数组为：";
    printVector(nums);
}
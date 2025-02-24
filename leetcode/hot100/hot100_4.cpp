#include <iostream>
#include <vector>
using namespace std;

/*
 * 这是一题比较新颖的二分查找，找到两个正序数组的中位数，可以把时间复杂度从(m + n)降低到 log(m + n)
 * 把两个数组都拆成左右两个部分 这样能够找到最中间的数
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2,nums1); // 保证nums1是最短的数组

    int m = nums1.size(),n = nums2.size();
    int left = 0,right = m,halfLen = (m + n + 1) / 2;

    while (left <= right) {
        int i = (left + right) / 2;
        int j = halfLen - i;
        int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
        int nums1RightMin = (i == m) ? INT_MAX : nums1[i];

        int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
        int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

        if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
            if ((m + n) % 2 == 0)
                return (max(nums1LeftMax,nums2LeftMax) + min(nums1RightMin,nums2RightMin)) / 2.0;
            else return max(nums1LeftMax,nums2LeftMax);
        }
        if (nums1LeftMax > nums2RightMin) right = i - 1;
        else left = i + 1;
    }

    return 0.0;
}
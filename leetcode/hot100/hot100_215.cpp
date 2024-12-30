#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


/*
 * 这里使用快速排序，实现找到第k大的元素
 * 可以使用堆 注意cpp中已经实现最大堆 最小堆 可以拿来调用
 * 记模板
 * 不要记这个快排模板 时间超限！！
 */
int partition1(vector<int>& nums, int left, int right) {
    int pivot = nums[right]; // 选择最后一个元素作为基准
    int i = left; // i存放比pivot小的区域的右边界

    for (int j = left; j < right; ++j) {
        if (nums[j] <= pivot) {
            swap(nums[i],nums[j]);
            i++;
        }
    }

    // 最后交换到正确的位置
    swap(nums[i],nums[right]);
    return i;
}

int quickSelect1(vector<int>& nums, int left, int right, int k) {
    // 在这里 k已经做过减法了 现在也就是找从左到右第k大的数了
    // 选择区分点
    int partitionIndex = partition1(nums,left,right);

    if (partitionIndex == k) return nums[partitionIndex];

    if (partitionIndex < k) return quickSelect1(nums,partitionIndex + 1,right,k);
    return quickSelect1(nums,left,partitionIndex - 1,k);
}

// 输入数组中有大量重复元素
// 三路归并排序 中间是一个区间
pair<int,int> partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int lt = left, i = left, gt = right;
    while (i <= gt) {
        if (nums[i] < pivot) swap(nums[lt++],nums[i++]);
        else if (nums[i] > pivot) swap(nums[i],nums[gt--]);
        else i++;
    }
    return {lt,gt};
}

int quickSelect(vector<int>& nums, int left, int right, int k) {
    auto[lt,gt] = partition(nums,left,right);
    if (k >= lt && k <= gt) return nums[k];
    if (k < lt) return quickSelect(nums,left,lt - 1,k);
    else return quickSelect(nums,gt + 1,right,k);
}


int findKthLargest(vector<int>& nums, int k) {
    return quickSelect1(nums,0,nums.size() - 1,nums.size() - k);
}

int findKthLargest2(vector<int>& nums, int k) {
    // 创建一个大小为k的最小堆
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num); // 将当前元素加入堆
        if (minHeap.size() > k) {
            minHeap.pop(); // 如果超过k那么删掉，这样最后保留的就是第k大的元素
        }
    }
    return minHeap.top();
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << "第 " << k << " 大的元素是 " << findKthLargest2(nums,k);
}
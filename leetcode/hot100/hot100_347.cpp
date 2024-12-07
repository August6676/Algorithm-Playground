#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;
/*
 * 第一种做法 使用最小堆
 * 第二种做法pass 有点复杂的快速排序
 */
vector<int> topKFrequent(vector<int>& nums, int k) {
    // 先统计每个数字出现的频率
    unordered_map<int,int> frequencyMap;
    for (int num : nums) {
        frequencyMap[num]++;
    }
    // 使用最小堆 按照频率从低到高排序 这里是一个lambda表达式
    // 如果定义为 frequencyMap[a] > frequencyMap[b]，堆会按照频率从小到大排序，变成了最小堆。
    // 如果定义为 frequencyMap[a] < frequencyMap[b]，堆会按照频率从大到小排序，保持为最大堆。
    // 使用 & 捕获表示通过引用访问 frequencyMap，在堆中动态查找频率值。
    auto cmp = [&frequencyMap](int a,int b) {
        return frequencyMap[a] > frequencyMap[b];
    };
    priority_queue<int,vector<int>,decltype(cmp)> minHeap(cmp);

    for (const auto& [num,freq] : frequencyMap) {
        minHeap.push(num);
        if (minHeap.size() > k) minHeap.pop();
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = topKFrequent(nums,k);
    for (int num: result) cout << num << " ";
}
#include <iostream>
#include <vector>
using namespace std;

int minStartValue(vector<int>& nums) {
    // 非常简单的前缀和的思想
    int currentprefix = 0,minprefix = 0;

    for (int num: nums) {
        currentprefix += num;
        minprefix = min(currentprefix,minprefix);
    }

    if (minprefix > 0) return 1;
    return 1 - minprefix;
}

int main() {
    vector nums = {-3,2,-3,4,2};

    cout << "最小的startValue为：" << minStartValue(nums);
}
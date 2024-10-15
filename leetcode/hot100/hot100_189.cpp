#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void rotate(vector<int>& nums,int k) {
    k = k %nums.size();
    if (k == 0) return;

    // reverse包含在algorithm中 含左边不含右边
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(),nums.begin() + k);
    reverse(nums.begin() + k,nums.end());
}

int main() {
    vector nums = {1,23,4,5,6,7,8,9};
    int k = 5;
    rotate(nums,k);
    for (int num: nums) {
        cout << num << " ";
    }

}
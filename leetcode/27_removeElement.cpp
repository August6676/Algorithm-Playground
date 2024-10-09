#include <vector>
#include <iostream>
using namespace std;

int removeElement(vector<int>& nums,int val) {
    int left =0,right = 0,count = 0;

    while (right < nums.size()) {
        // right只有不是目标元素的时候才和左交换 否则一直向右移动 左只有不是val和被交换了之后才右移
        if (nums[right] != val) {
            swap(nums[left],nums[right]);
            left++;
            count++;
        }
        right++;
    }
    return count;
}

int main() {
    vector nums = {3,2,2,3};
    int val = 3;
    int x = removeElement(nums,val);
    cout << "含有除了3的个数为：" << x << endl;
    cout << "移动元素后的数组为：" << endl;
    for (int i = 0 ; i < x; i++) {
        cout << nums[i] << " ";
    }

}
#include <vector>
#include <iostream>
using namespace std;

int maxArea(vector<int>& height) {
    int maxSize = 0,left = 0,right = height.size() - 1;
    while (left < right) {
        int currentSize= min(height[left],height[right]) * (right - left);
        if (left <= right) left ++;
        else right --;
        maxSize = max(currentSize,maxSize);
    }
    return maxSize;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "最大的容量为" << maxArea(height);
}
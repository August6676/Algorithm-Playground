#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1,vector<int>& nums2) {
    unordered_map<int,int> nextGreater;
    stack<int>s;

    for (int num : nums2) {
        while (!s.empty() && s.top() < num) {
            nextGreater[s.top()] = num;
            s.pop();
        }
        s.push(num);
    }

    while (!s.empty()) {
        nextGreater[s.top()] = -1;
        s.pop();
    }

    vector<int> ans;
    for (int num: nums1) {
        ans.push_back(nextGreater[num]);
    }
    return ans;
}

int main() {
    vector<int> nums1 = {2,4};
    vector<int> nums2 = {1,2,3,4};
    vector<int> ans;
    ans = nextGreaterElement(nums1,nums2);
    for (int num : ans) {
        cout << num << " " << endl;
    }
}
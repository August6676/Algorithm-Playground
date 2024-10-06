#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> paramMap; // string

    for (string s:strs) {
        string sortedString = s;
        sort(sortedString.begin(),sortedString.end()); // algorithm
        // 以排序后作为键，原数作为值
        paramMap[sortedString].push_back(s);
    }
    vector<vector<string>> ans;

    // 哈希表的遍历
    for (auto& entry: paramMap) {
        ans.push_back(entry.second);
    }

    return ans;
}

int main() {
    vector<string> s = {"eat","ate","tan","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(s);
    for (vector<string> ss : ans) {
        for (string sss: ss) {
            cout << sss << " ";
        }
        cout << endl;
    }
}
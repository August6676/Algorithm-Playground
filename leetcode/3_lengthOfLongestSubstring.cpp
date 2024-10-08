#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
/*
 *  双指针法
 * */
int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    unordered_map<char,int> charToindex;
    int left = 0,maxLength = 0;
    for (int right = 0; right < s.size(); right++) {
        if (charToindex.count(s[right]) && charToindex[s[right]] >= left)
            left = charToindex[s[right]] + 1; // 如果该字符的索引在左边界右侧则更新左边界
        charToindex[s[right]] = right;
        maxLength = max(maxLength,right - left + 1);
    }
    return maxLength;
}

int main() {
    string s = "abcbcddfashea";
    cout << "无重复字符的最长子串长度为：" << lengthOfLongestSubstring(s) << endl;
}
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * hard题目
 * 使用两个哈希表代表t中的数值 滑动窗口中的
 * 右移的过程中不断更新
 */
string minWindow(string s, string t) {
    unordered_map<char,int> need,window;
    for (char c: t) need[c]++;

    int start = 0;
    int left = 0,right = 0;
    int minLen = INT_MAX,valid = 0;

    while (right < s.size()) {
        char c = s[right];
        right++;
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) valid++;
        }

        while (valid == need.size()) {
            if (right - left < minLen) {
                start = left;
                minLen = right - left;
            }
            char d = s[left];
            left++;
            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
            }
            window[d]--;
        }
    }

    return minLen == INT_MAX ? "":s.substr(start,minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t ="ABC";
    cout << "最小覆盖子串为 " << minWindow(s,t) << endl;
}

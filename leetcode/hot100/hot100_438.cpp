#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findAnagrams(string s,string p) {
    vector<int> result;
    int s_len = s.size(),p_len = p.size();
    if (s_len < p_len) return result;

    // 使用两个数组来存储次数
    vector p_frequency(26,0);
    vector window_freq(26,0);

    // 第一个窗口
    for (int i = 0; i < p_len; i++) {
        window_freq[s[i] - 'a']++;
        p_frequency[p[i] - 'a']++;
    }
    if (window_freq == p_frequency) result.push_back(0);

    for (int i = p_len; i < s_len; i++) {
        // 窗口右移过程
        window_freq[s[i] - 'a']++;
        window_freq[s[i - p_len] - 'a']--;

        if (window_freq == p_frequency) result.push_back(i - p_len + 1); //注意这个起点位置要对
    }

    return result;
}

int main() {
    string s = "cbaebabacd",p = "abc";
    cout << "s字符串中所有异位词的开始下标为：";
    vector<int> ans = findAnagrams(s,p);
    for (int num: ans) {
        cout << num << " ";
    }
}
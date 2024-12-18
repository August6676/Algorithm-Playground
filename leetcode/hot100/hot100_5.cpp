#include <iostream>
#include <vector>
using namespace std;

/*
 * 最长回文字串
 * 使用二维动态规划 dp[i][j]表示从i到j的字符串！
 */
string longestPalindrome(string s) {
    int n = s.size();
    if (n < 2) return s;

    vector<vector<bool>> dp(n,vector<bool>(n,false));
    int start = 0,maxLength = 1;

    // 处理单个字符的情况
    for (int i = 0; i < n; i++) dp[i][i] = true;

    // 长度为2的情况
    for (int i = 0; i < n - 2;i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] =true;
            start = i;
            maxLength = 2;
        }
    }

    // 检查长度大于 2 的子串
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;

            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxLength = length;
            }
        }
    }

    return s.substr(start,maxLength);
}

int main() {
    string s = "babad";
    cout << "最长回文子串为：" << longestPalindrome(s);
}
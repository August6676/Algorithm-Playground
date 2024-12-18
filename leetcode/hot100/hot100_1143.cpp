#include <iostream>
#include <vector>
using namespace std;

/*
 * 动态规划 但是dp表示的是从0开始长度为i和场电影为j的序列的公共子序列长度
 * 没做对 对于dp的想法想错了
 */
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();

    vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    cout << "最长公共子序列长度为：" << longestCommonSubsequence(text1,text2);
}

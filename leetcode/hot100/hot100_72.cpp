#include <vector>
#include <iostream>
using namespace std;

/*
 * NLP课上讲过的最短编辑距离 和1143题目类似
 * 注意m n表示的实际含义 在对应到字符串中 下标应该是i - 1 j - 1
 */
int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1]) + 1;
        }
    }
    return dp[m][n];
}

int main() {
    string word1 = "horse";
    string word2 = "ros";
    cout << "把 " << word1 << " 换成 " << word2 << " 所需的最小操作数为：" << minDistance(word1,word2);
}

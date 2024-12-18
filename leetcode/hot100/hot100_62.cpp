#include <iostream>
#include <vector>
using namespace std;

/*
 * 比较简单的多维动态规划
 */
int uniquePaths(int m, int n) {
    // 初始化固定大小的二维数组
    vector<vector<int>> dp(m,vector<int>(n,0));

    for (int i = 0; i < n; i++) dp[0][i] = 1;

    for (int i = 1; i < m;i++) {
        dp[i][0] = 1;
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    return dp[m - 1][n - 1];
}


int main() {
    int m = 3;
    int n = 7;
    cout << "路径总和为" << uniquePaths(m,n);
}
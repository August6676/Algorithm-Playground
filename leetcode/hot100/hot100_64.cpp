#include <iostream>
#include <vector>
using namespace std;

/*
 * 还是一道基本的动态规划
 * 这种都是从左上角往右下角 不走回头路
 * 先把第一排第一列做好了 之后使用递归式
 */
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = grid[0][0];

    for (int i = 1; i < n; i++) dp[0][i] = dp[0][i - 1] + grid[0][i];

    for (int i = 1; i < m; i++) {
        dp[i][0] = grid[i][0] + dp[i - 1][0];
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j] + grid[i][j],dp[i][j - 1] + grid[i][j]);
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    vector<vector<int>> grid = {{1,2,3},{4,5,6}};
    cout << "路径总和最小为： " << minPathSum(grid);
}
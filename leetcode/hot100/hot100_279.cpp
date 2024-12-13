#include <iostream>
using namespace std;
#include <vector>

/*
 * 动态规划，但是自己做麻烦了
 * 注意状态转移方程：其实只要考虑平方根就可以
 * dp[i] = min(dp[i-j*j] + 1)
 */
int numSquares(int n) {
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;

    // 预算小于等于n的完全平方数哦
    vector<int> squares;
    for (int i = 1; i * i <= n;i++) {
        squares.push_back(i * i);
    }

    // 执行动态规划
    for (int i = 1; i <= n;i++) {
        for (int square:squares) {
            if (i < square) break;
            dp[i] = min(dp[i],dp[i - square] + 1);
        }
    }
    return dp[n];
}

int main() {
    cout << "输入一个整数：" ;
    int n;
    cin >> n;
    cout << "和为" << n << "的完全平方数的最少数量是：" << numSquares(n) << endl;
}
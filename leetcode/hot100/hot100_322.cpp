#include <iostream>
#include <vector>
using namespace std;

/*
 * 依然是动态规划
 * 思路和 279.完全平方数 有点像
 * 稍有区别
 */
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1,INT_MAX);
    dp[0] = 0;

    for (int coin : coins) {
        for (int i = coin; i <= amount;i++) {
            if (dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i],dp[i - coin] + 1);
        }
    }

    return dp[amount] == INT_MAX ? -1:dp[amount];
}

int main() {
    vector<int> coins = {1,2,5};
    int amount = 11;
    int ans = coinChange(coins,amount);
    if (ans == -1)
        cout << "无法组成该金额";
    else
        cout << "组成该金额的最少硬币个数为" << ans;
}
#include <iostream>
#include <unordered_set>
using namespace std;
#include <vector>
/*
 * 还是动态规划算法！
 * dp[i]表示从0开始到i能不能由wordDict中的单词构成
 * 感觉自己思维不够灵活
 */
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    // 用哈希表存储 查找更快
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

    vector<bool> dp(n + 1,false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i;j++) {
            if (dp[j] && wordSet.find(s.substr(j,i - j)) != wordSet.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    string s = "catsandog";

    if (wordBreak(s,wordDict)) cout << "可以拼接出";
    else cout << "不能拼接出";
}

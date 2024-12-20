#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 * 自己想的时候 结合了动态规划和栈
 * 但是还没有完全组织好代码
 * 这里dp[i]表示以i结尾的最长连续有效串的长度
 * 最后使用max_element()函数返回
 */
int longestValidParentheses(string s) {
    if (s.empty()) return 0;
    int n = s.size();
    vector<int> dp(n,0);
    stack<int> leftStack;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            leftStack.push(i);
        else {
            if (!leftStack.empty()) {
                int start = leftStack.top();
                leftStack.pop();
                dp[i] = i - start + 1 + (start > 0 ? dp[start - 1] : 0);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    string s = "()(()))";
    cout << "最长有效括号为" << longestValidParentheses(s);
}

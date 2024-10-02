#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int current,prev1 = 1,prev2 = 2; // 不需要使用哈希表 直接用两个变量来回交换就能实现
    for (int i = 3;i <= n; i++) {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }

    return prev2;
}

int main () {
    cout << "请输入楼梯阶数：";
    int n;
    cin >> n;
    cout << "爬楼梯的方法共有" << climbStairs(n) << "种。" << endl;
}

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
/*
 * 使用最小堆的思想 不断取出顶部元素
 * 自己做的时候 对于第n个的处理搞麻烦了
 */
int nthUglyNumber(int n) {
    priority_queue<long,vector<long>,greater<long>> minHeap; // 使用long类型 防止溢出
    unordered_set<int> seen;

    minHeap.push(1);
    seen.insert(1); // 向hashset中插入也可以用insert emplace稍有区别

    vector<int> factors = {2,3,5};
    long currentUgly = 1;

    for (int i = 1; i <= n; i++) {
        currentUgly = minHeap.top();
        minHeap.pop();

        for (int factor:factors) {
            long newUgly = currentUgly * factor;
            if (seen.find(newUgly) == seen.end()) {
                minHeap.push(newUgly);
                seen.insert(newUgly);
            }
        }
    }
    return (int)currentUgly;
}

int main() {
    int n = 1000;
    cout << "第 " << n << " 个丑数是 " << nthUglyNumber(n);
}
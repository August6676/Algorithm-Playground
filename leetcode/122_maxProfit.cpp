#include <iostream>
#include <vector>
using namespace std;

/*
 * 比较简单的贪心
 */
int maxProfit(vector<int>& prices) {
    int result = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
        result += max(prices[i + 1] - prices[i],0);
    }
    return result;
}

int main() {
    vector<int> prices = {1,2,3,4,5};
    cout << "最大利润为：" << maxProfit(prices);
}
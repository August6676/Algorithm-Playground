#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minprice = 10000000;
    int maxprofit = 0;
    for (int price :prices) {
        maxprofit = max(maxprofit,price - minprice);
        minprice = min(minprice,price);
    }
    return maxprofit;
}

int main() {
    vector prices = {1,3,5,8,2,10,0,7};
    cout << "最大的利润为： " << maxProfit(prices) << endl;
}
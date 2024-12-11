#include <vector>
#include <iostream>
using namespace std;
/*
 * 使用贪心算法进行优化
 * 如果从x可以到达y 到不了y + 1 就说明新的起点只能从 y + 1开始，因为之前都是有余量的
 * 同时遍历到结尾 不用再从头开始再遍历一遍 妙哉
 */
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = 0,current_gas = 0,total_gas = 0;

    for (int i = 0; i < gas.size();i++) {
        current_gas += gas[i] - cost[i];
        total_gas += gas[i] - cost[i];

        if (current_gas < 0) {
            current_gas = 0;
            start = i + 1;
        }
    }
    return total_gas >= 0 ? start: -1;
}

int main() {
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,2,1};
    if (canCompleteCircuit(gas,cost) == -1) cout << "无论怎样，你都不可能绕环路行驶一周";
    else cout << "你能从序号为 " <<canCompleteCircuit(gas,cost) << " 开始绕行一周" << endl;
}
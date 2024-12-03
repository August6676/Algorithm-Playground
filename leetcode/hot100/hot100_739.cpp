#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 * 使用单调栈，保存数组中尚未找到比它更大的温度的索引，而不是采用遍历的思想一直寻找
 */
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> result (temperatures.size(),0); // 初始化结果数组
    stack<int> s; // 单调递减栈，存储索引

    for (int i = 0; i < temperatures.size(); i++) {
        while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
            int index = s.top();
            s.pop();
            result[index] = i - index; // 保存距离
        }
        // 当前索引入栈
        s.push(i);
    }
    return result;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);
    for (const auto& re: result) {
        cout << re << " ";
    }
}
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
/*
 * 我的评价是难度不大，但是涉及到很多STL的基本操作，卡住了
 * 1. reverse array 正确用法reverse(begin(),end())
 * 2. 判断char是否为数字类型 isdigit()
 * 3. 字符串转为数字stoi(str)
 */
string decodeString(string s) {
    string result = "";
    stack<char> sstack;
    for (char c: s) {
        if (c != ']') sstack.push(c);
        else {
            string temp = "";
            while (sstack.top() != '[') {
                temp.push_back(sstack.top());
                sstack.pop();
            }
            reverse(temp.begin(), temp.end());
            sstack.pop();
            string numStr = "";
            while (!sstack.empty() && isdigit(sstack.top())) {
                numStr.push_back(sstack.top());
                sstack.pop();
            }
            reverse(numStr.begin(), numStr.end());
            int num = stoi(numStr);
            string temp_s = "";
            for (int i = 0;i < num;i++) {
                for (char cc:temp) {
                    temp_s.append(1,cc);
                }
            }

            for (char x:temp_s) {
                sstack.push(x);
            }
        }
    }

    while (!sstack.empty()) {
        result.push_back(sstack.top());
        sstack.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}


int main() {
    string encoded = "3[a2[c]]";
    cout << decodeString(encoded) << endl; // 输出: accaccacc
    return 0;
}
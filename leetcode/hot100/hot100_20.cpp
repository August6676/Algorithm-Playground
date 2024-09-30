#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool isValid(string s) {
    stack<char> Sstack;
    unordered_map<char,char> matching = {
        {')','('},
        {']','['},
        {'}','{'}
    }; // 注意这里是反着的！！

    for (char ch : s) {
        if (matching.count(ch) == 0) Sstack.push(ch); // 如果为0 代表没有这个键 说明不是右括号！ count统计是否有这个键
        else {
            if (Sstack.empty() || Sstack.top() != matching[ch]) return false;
            Sstack.pop();
        }
    }

    return Sstack.empty(); // 栈为空代表匹配 不为空则有问题
}

int main() {
    vector<string> s;
    string s1 = "[]{}{}()";
    string s2 = "{[]}((";
    string s3 = "((";
    s.push_back(s1);
    s.push_back(s2);
    s.push_back(s3);
    for (const auto& x : s) {
        cout << "字符串为：" << x << " ";
        if (isValid(x)) cout << "是有效括号" << endl;
        else cout << "不是有效括号" << endl;
    }
    return 0;
}
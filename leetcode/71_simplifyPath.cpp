#include <stack>
#include <iostream>
using namespace std;

string simplifyPath(string path) {
    stack<string> sStack;
    string token;
    path += '/'; // 防止最后一个token不在处理范围内

    for (char ch :path) {
        if (ch == '/') {
            if (!token.empty()) {
                if (token == "..") {
                    if (!sStack.empty()) sStack.pop();
                }
                else if (token != ".") sStack.push(token);
                token.clear(); // 置为空
            }
        } else token += ch;
    }

    string result;
    // 这里可以在最前面添加 用不着再加一个vector逆向输出啥的
    while (!sStack.empty()) {
        result = '/' + sStack.top() + result;
        sStack.pop();
    }
    return result.empty() ? "/" : result;
}

int main() {
    string path = "/.../a/../b/c/../d/.";
    string reslut = simplifyPath(path);
    cout << reslut << endl;
}
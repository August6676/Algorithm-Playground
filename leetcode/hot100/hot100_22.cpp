#include <iostream>
#include <vector>
using namespace std;

void backtrack(int n,int current_left,int current_right,vector<string>& result,string current) {
    if (current_right > current_left || current_left > n || current_right > n) return;
    if (current_left == n) {
        current.append(n - current_right,')');
        result.push_back(current);
        return;
    }

    if (current_left == 0) {
        current.push_back('(');
        backtrack(n,current_left + 1,current_right,result,current);
        current.pop_back();
    } else {
        current.push_back('(');
        backtrack(n,current_left + 1,current_right,result,current);
        current.pop_back();
        current.push_back(')');
        backtrack(n,current_left,current_right + 1,result,current);
        current.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    backtrack(n,0,0,result,current);
    return result;
}

int main() {
    int n;
    cout << "请输入n:";
    cin >> n;

    vector<string> result;
    result = generateParenthesis(n);
    for (const auto& str: result) {
        cout << str << " ";
    }

}
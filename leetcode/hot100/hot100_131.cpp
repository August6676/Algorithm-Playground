#include <iostream>
#include <vector>
using namespace std;

// 判断回文数组
bool isPalindrome(string s) {
    int front = 0;
    int end = s.length() - 1;
    while (front <= end) {
        if (s[front] != s[end]) return false;
        front++;
        end--;
    }
    return true;
}
// 进行回溯
void backtrack(int start_index,int end_index,vector<string>& method,vector<vector<string>>& result,string s) {
    // 整个数组都遍历结束，那么加入大数组 直接返回
    if (start_index == s.length()) {
        result.push_back(method);
        return;
    }
    // 如果超出当前数组边界 那么返回
    if (end_index >= s.length()) return;
    // 如果是回文串 那么加入method，进行下一步回溯
    if (isPalindrome(s.substr(start_index,end_index - start_index + 1))) {
        method.push_back(s.substr(start_index,end_index - start_index + 1));
        backtrack(end_index + 1,end_index + 1,method,result,s);
        method.pop_back();
    }
    for (int i = end_index + 1; i < s.length(); i++) {
        if (isPalindrome(s.substr(start_index,i - start_index + 1))) {
            method.push_back(s.substr(start_index,i - start_index + 1));
            backtrack(i + 1,i + 1,method,result,s);
            method.pop_back();
        }
    }

}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> method;
    backtrack(0,0,method,result,s);
    return result;
}


int main() {
    string s = "aabb";
    vector<vector<string>> result = partition(s);
    for (const auto& subs: result) {
        cout << endl;
        for (const auto& subss:subs) {
            cout << subss << " ";
        }
    }
}
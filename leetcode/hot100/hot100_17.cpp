#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

void backtrack(string& digits,int index,string combination,unordered_map<char,string>& phoneMap,vector<string>& combinations) {
    if (index == digits.length()) { // 字符串是.length()计算长度
        combinations.push_back(combination);
        return;
    }
    string& letters = phoneMap.at(digits[index]);

    for (const auto& letter: letters) {
        combination.push_back(letter);
        backtrack(digits,index + 1,combination,phoneMap,combinations);
        combination.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> combinations;
    if (digits.empty()) return combinations;

    unordered_map<char,string> phoneMap = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

    string combination;
    backtrack(digits,0,combination,phoneMap,combinations);
    return combinations;
}

int main() {
    string digits = "236";
    vector<string> result = letterCombinations(digits);
    for (const auto& s: result) {
        cout << s << endl;
    }
    return 0;
}
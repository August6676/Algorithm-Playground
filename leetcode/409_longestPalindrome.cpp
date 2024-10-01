#include <iostream>
#include <unordered_map>
using namespace std;

int longestPalindrome(string s) {
    unordered_map<char,int> count;
    int length = s.size();
    int odd = 0; // 奇数元素的个数

    for (char ch : s) {
        if (count.find(ch) == count.end()) {
            count[ch] = 1;
            odd ++;
        }
        else {
            count[ch] ++;
            if (count[ch] % 2 == 0) odd--;
            else odd ++;
        }
    }

    if (odd == 0 || odd == 1) return length;
    return length - odd + 1;
}

int main() {
    string s = "1234688765543";
    cout << "由nums构成的最长回文串为：" << longestPalindrome(s) << endl;
}
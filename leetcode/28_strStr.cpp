#include <iostream>
#include <string>
using namespace std;

// 这个题目标签是双指针，但是其实如下办法简单易懂，虽然也是暴解，不过学习substr的用法
int strStr(string haystack,string needle) {
    if (haystack.size() < needle.size()) return -1;

    int hlength = haystack.size();
    int nlength = needle.size();

    for (int i = 0; i < hlength - nlength + 1; i++) {
        if (haystack.substr(i,nlength) == needle) return i;
    }
    return  -1;
}

int main() {
    string haystack = "sadbutsad",needle = "sad";
    cout << "第一个匹配的下标是 " << strStr(haystack,needle);
}
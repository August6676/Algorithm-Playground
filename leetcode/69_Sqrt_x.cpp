#include <iostream>
using namespace std;

int mySqrt(int x) {
    // 其实就是寻找平方最接近x并且小于x的数
    if (x == 0 || x == 1) return x;

    int left = 0,right = x,ans;

    while (left <= right) {
       int mid = left +(right - left) / 2; // 这种写法避免了 (left+right) / 2 这种做法可能的溢出

        if (mid <= x / mid) { // 妙在这里，其实将小于和等于两种情况合并了
            ans = mid;
            left = mid + 1;
        } else right = mid - 1;
    }
    return ans;
}

int main() {
    int x;
    cout << "请输入一个正整数：";
    cin >> x;
    int s = mySqrt(x);
    cout << "该数的算术平方根为：";
    cout << s;
}
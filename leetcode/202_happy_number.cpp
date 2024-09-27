#include <iostream>
#include <unordered_set> // unordered_set存储不重复的元素
using namespace std;

int square_sum(int n) { // cpp执行数位分离
    int n_sum = 0;
    while (n != 0) {
        int digit = n % 10;
        n = n /10;
        n_sum += digit * digit;
    }
    return n_sum;
}

bool isHappy(int n) {
    unordered_set <int> hashSet;
    while (n != 1) {
        n = square_sum(n);
        if (hashSet.find(n) != hashSet.end()) return false;
        else hashSet.insert(n);
    }
    return true;
}

int main() {
    int n;
    cout << "请输入一个整数：";
    cin >> n;
    if (isHappy(n))
        cout << n << "是快乐数" << endl;
    else
        cout << n << "不是快乐数" << endl;
}

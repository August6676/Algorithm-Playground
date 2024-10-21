#include <iostream>
#include <vector>
using namespace std;

/*
 *  和54题目逻辑一样 只是变成了填充矩阵
 *  螺旋遍历 记这个思路
 * */
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n,vector<int>(n,0)); // 初始化一个二维矩阵
    int left = 0,right = n - 1,top = 0,bottom = n - 1;
    int num = 1;
    while (left <= right && top <= bottom) {
        for (int i = left;i <= right; i++) {
            ans[top][i] = num;
            num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            ans[i][right] = num;
            num++;
        }
        right--;

        for (int i = right; i >= left; i--) {
            ans[bottom][i] = num;
            num++;
        }
        bottom--;

        for (int i = bottom; i >= top;i--) {
            ans[i][left] = num;
            num++;
        }
        left++;
    }
    return ans;
}

int main() {
    int n;
    cout << "请输入你想要生成的数：";
    cin >> n;
    vector ans(n,vector(n,0));
    ans = generateMatrix(n);

    for (const vector<int>& target: ans) {
        for (int num: target) {
            cout << num << " ";
        }
        cout << endl;
    }
}
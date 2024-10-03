#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    if (numRows == 1) return {{1}}; // vector用{}包裹
    vector<vector<int>> ans(numRows); // 分配空间

    for (int i = 0; i < numRows; i++) {
        ans[i].resize(i + 1);
        ans[i][0] = 1;
        ans[i][i] = 1;

        for (int j = 1;j < i; j++) { // 注意下标开始的位置
            ans[i][j] = ans[i - 1][j - 1]+ ans[i - 1][j];
        }
    }
    return ans;
}

int main() {
    cout << "请输入杨辉三角的行数：";
    int n;
    cin >> n;
    vector<vector<int>> ans;
    ans = generate(n);
    for (int i = 0; i < ans.size();i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
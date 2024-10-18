#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    // 非常不喜欢这类题目，思路不难但是一点也不容易做对
    // 注意数组表示元素左右的顺序
    if (matrix.empty()) return {};
    int left = 0,right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1,top = 0;
    vector<int> ans;

    while (left <= right && top <= bottom) {
        // 从左到右
        for (int i = left; i <= right;i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // 从上到下
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // 从右到左
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // 从下往上
        if (left <= right) {
            for (int i = bottom; i >= top;i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans = spiralOrder(matrix1);
    for (int an: ans) {
        cout << an << " ";
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    // 矩阵相关操作有很多trick
    int n = matrix.size();
    // 1.矩阵转置
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    // 2.矩阵水平翻转
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "旋转前：" << endl;
    for (int i  = 0; i < matrix.size();i++) {
        for (int j = 0 ; j < matrix[0].size();j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    rotate(matrix);
    cout << "旋转后：" << endl;
    for (int i  = 0; i < matrix.size();i++) {
        for (int j = 0 ; j < matrix[0].size();j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
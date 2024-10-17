#include <vector>
#include <iostream>
using namespace std;
/*
 *  不适用额外空间，同时时间复杂度仍为mn
 *  但是其实感觉如果用比较笨的使用额外数组，也不会运行特别复杂
 * */
void moveZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size(),cols = matrix[0].size();
    bool firstRowZero = false,firstColZero = false;

    // 标记第一行 第一列是不是0
    for (int i = 0; i < rows;i++) {
        if (matrix[i][0] == 0) firstColZero = true;
    }
    for (int j = 0; j< cols;j++) {
        if (matrix[0][j] == 0) firstRowZero = true;
    }

    // 根据0的位置，用第一行第一列标记是不是0
    for (int i = 0; i < rows;i++) {
        for (int j = 0; j < cols;j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
// 更新行和更新列的时候 要跳过0这个位置 因为这个位置被作为标记位！
    // 更新行
    for (int i = 1; i < rows;i++) {
        if (matrix[i][0] == 0) {
            for (int j = 0; j < cols;j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // 更新列
    for (int j = 1; j < cols; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 0; i < rows; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    // 最后看第一行 第一列是不是0
    if (firstRowZero) {
        for (int i = 0;i < cols;i++) matrix[0][i] = 0;
    }
    if (firstColZero) {
        for (int j = 0; j < rows;j++) matrix[j][0] = 0;
    }
}

int main() {
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    cout << "原数组为：" << endl;
    for (int i = 0; i < matrix.size();i++) {
        for (int j = 0; j <matrix[0].size();j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    moveZeroes(matrix);
    cout << "移动0后的数组为：" << endl;
    for (int i = 0; i < matrix.size();i++) {
        for (int j = 0; j <matrix[0].size();j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
#include <iostream>
using namespace std;
#include <vector>

/*
 *  和hot100 240一样的思路
 * */
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(),n = matrix[0].size();
    int row = 0,col = n -1;

    while (row < m && col >=0) {
        if (matrix[row][col] == target) return true;
        if (matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << "请输入要查找的数值：" ;
    int n;
    cin >> n;
    if (searchMatrix(matrix,n)) cout << "在二维矩阵中";
    else cout << "不在二维矩阵中";
}
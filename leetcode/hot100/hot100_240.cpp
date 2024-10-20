#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix,int target) {
   if (matrix.empty() || matrix[0].empty()) return false;

   int rows = matrix.size(),cols = matrix[0].size();
   int row = 0,col = cols - 1;

   while (row < rows && col >= 0) {
      if (matrix[row][col] == target) return true;
      if (matrix[row][col] > target) col--;
      else row++;
   }
   return false;
}

int main() {
   vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
   int n;
   cout << "请输入target = ";
   cin >> n;
   if (searchMatrix(matrix,n)) cout << "矩阵中存在该元素";
   else cout << "矩阵中不存在该元素";
}
#include <iostream>
#include <vector>
using namespace std;
/*
 * 著名的n皇后问题
 * 注意如何表示对角线：diagonal数组 因为都是在一条直线上 所以肯定满足某种线性关系 用这样表示是否在同一个对角线上
 */
void backtrack(vector<vector<string>>& result,vector<string>& board,int row,int n,vector<int>& cols,vector<int>& diagonal1,vector<int>& diagonal2) {

    if (row == n) {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (cols[col] || diagonal1[row - col + n - 1] || diagonal2[row + col]) continue;

        board[row][col] = 'Q';
        cols[col] = 1;
        diagonal1[row - col + n - 1] = 1;
        diagonal2[row + col] = 1;

        backtrack(result,board,row + 1,n,cols,diagonal1,diagonal2);

        board[row][col] = '.';
        cols[col] = 0;
        diagonal1[row - col + n - 1] = 0;
        diagonal2[row + col] = 0;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n,string(n,'.'));
    vector<int> cols(n,0),diagonal1(2 * n - 1,0),diagonal2(2 * n - 1,0);
    backtrack(result,board,0,n,cols,diagonal1,diagonal2);
    return result;
}

int main() {
    vector<vector<string>> result;
    int n;
    cin >> n;
    result = solveNQueens(n);
    for (const auto& vec: result) {
        for (const auto& str: vec)
            cout << str << endl;
        cout << endl;
    }
}

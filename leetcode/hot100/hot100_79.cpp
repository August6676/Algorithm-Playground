#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<char>>& board,string word,int current_index,int current_row,int current_column,bool& flag,vector<vector<bool>>& note) {
    if (flag) return; // 如果已经找到单词，直接返回
    if (current_index == word.length() - 1) { // 找到了完整单词
        flag = true;
        return;
    }

    // 四个方向移动
    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    // 可以用这样数组的方式记录方位
    for (auto& dir: directions) {
        int new_row = current_row + dir.first;
        int new_column = current_column + dir.second;

        // 检查边界条件和访问状态
        if (new_row >= 0 && new_row < board.size() && new_column >= 0 && new_column < board[0].size()) {
            if (note[new_row][new_column]) {
                if (board[new_row][new_column] == word[current_index + 1]) {
                    note[new_row][new_column] = false;
                    backtrack(board,word,current_index + 1,new_row,new_column,flag,note);
                    note[new_row][new_column] = true; // 这一步回溯要恢复状态！
                }
            }
        }
    }
}

bool exist(vector<vector<char>>& board, string word) {
    bool flag = false;

    for (int i = 0; i < board.size();i++) {
        for (int j = 0; j < board[0].size();j++) {
            if (board[i][j] == word[0]) {
                vector note (board.size(),vector(board[0].size(),true));
                note[i][j] = false;
                backtrack(board,word,0,i,j,flag,note);
                if (flag) return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','F'}};
    string word ="ABCB";
    if (exist(board,word)) cout << "存在该单词";
    else
        cout << "没有该单词";
}

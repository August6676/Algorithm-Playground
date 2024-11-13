#include <vector>
#include <iostream>
using namespace std;
/*
 * 使用深度优先遍历，使用0标记已经走过的格子
 */
void dfs(vector<vector<char>>& grid,int i,int j) {
    int rows = grid.size();
    int cols = grid[0].size();

    // 到边界了或者是碰到水了
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0' ) {
        return;
    }

    // 标记当前格子为水，表示已访问
    grid[i][j] = '0';

    // 四个方向进行dfs
    dfs(grid,i - 1,j);
    dfs(grid,i + 1,j);
    dfs(grid,i,j - 1);
    dfs(grid,i,j + 1);
}

int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int num = 0;

    for (int i = 0; i < rows;i++) {
        for (int j = 0; j < cols;j++) {
            if (grid[i][j] == '1') {
                num++;
                dfs(grid,i,j);
            }
        }
    }
    return num;
}

int main() {
    vector<vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
    };
    cout << "岛屿数量为：" << numIslands(grid) << endl;
}


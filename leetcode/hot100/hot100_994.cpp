#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int,int>> rottenQueue;
    int freshCount = 0;

    // 统计新鲜🍊，把腐烂的🍊加入队列
    for (int i = 0; i < m;i++) {
        for (int j = 0; j < n;j++) {
            if (grid[i][j] == 2) rottenQueue.push({i,j});
            else if (grid[i][j] == 1) freshCount++;
        }
    }
    if (freshCount == 0) return 0; // 没有新鲜🍊 直接返回
    int time = 0;

    vector<int> directions = {-1,0,1,0,-1}; // 4个方向

    while (!rottenQueue.empty()) {
        int currentSize = rottenQueue.size();
        bool hasRotten = false;

        for (int i = 0;i < currentSize;i++) {
            int x = rottenQueue.front().first;
            int y = rottenQueue.front().second;
            rottenQueue.pop();

            // 对4个方向进行腐烂传播
            for (int d = 0; d < 4;d++) {
                int nx = x + directions[d];
                int ny = y + directions[d + 1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    hasRotten = true;
                    grid[nx][ny] = 2;
                    rottenQueue.push({nx,ny});
                    freshCount--;
                }
            }
        }
        if (hasRotten) time++; // 这个位置放错会导致计数不准确
    }

    return freshCount == 0 ? time : -1; // 如果还有新鲜🍊，返回-1
}

int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    cout << "全部腐烂需要 " << orangesRotting(grid) << " 分钟";
}
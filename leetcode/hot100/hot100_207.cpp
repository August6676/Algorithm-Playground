#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*
 * 拓扑排序+BFS
 * 构建图，记录入度
 * 最后看有没有入度不为0的
 * 也可以改为栈 如果用栈 就成了深度优先搜索
 */
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses); // 邻接表
    vector<int> inDegree(numCourses,0); // 入度的表

    for (const auto& pre: prerequisites) {
        adj[pre[1]].push_back(pre[0]);
        inDegree[pre[0]]++;
    }

    // 把所有入度为0的节点加入队列
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    int visited = 0;

    // 执行BFS
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        visited++;

        for (int next: adj[top]) {
            inDegree[next]--;
            if (inDegree[next] == 0) q.push(next);
        }
    }
    // 还剩吗？
    return visited == numCourses;
}

int main() {
    vector<vector<int>> prerequisites = {
    {0,1},
        {2,3},
        {3,1}
    };
    if (canFinish(4,prerequisites)) cout << "这是可能的" << endl;
    else cout << "这是不可能的" << endl;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * 依然是使用拓扑排序
 * 注意队列的基本用法 push pop front
 */
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses);

    for (const auto& pre: prerequisites) {
        adj[pre[1]].push_back(pre[0]);
        inDegree[pre[0]]++;
    }

    vector<int> order;
    queue<int> q;

    for (int i = 0; i < inDegree.size();i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int current = q.front();
        order.push_back(current);
        q.pop();

        for (int next: adj[current]) {
            inDegree[next]--;
            if (inDegree[next] == 0) q.push(next);
        }
    }

    return order.size() == numCourses ? order : vector<int> {};
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
    {1,0},
        {2,0},
        {3,1},
        {3,2}
    };
    vector<int> result = findOrder(numCourses,prerequisites);
    cout << "可能的顺序为: " << endl;
    for (int num: result) {
        cout << num << " ";
    }
}
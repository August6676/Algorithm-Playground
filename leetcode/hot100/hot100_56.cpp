#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 *  有点贪心算法，但是并不难想 大概两次AC
 * */
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 1) return intervals;
    vector<vector<int>> ans;
    // 👇这个排序 会先按照每个vector的第一个元素排序，第一个相同的话按照第二个排序
    sort(intervals.begin(), intervals.end());
    int left = intervals[0][0],right = intervals[0][1];

    for (int i = 1; i < intervals.size();i++) {
        if (intervals[i][0] > right) {
            ans.push_back({left,right}); // 不用vector 用大括号表示
            left = intervals[i][0];
            right = intervals[i][1];
        } else {
            right = max(intervals[i][1],right);
        }
    }

    ans.push_back({left,right}); // 最后把一个push进去
    return ans;
}

int main() {
    vector<vector<int>> integrals = {{1,3},{2,6},{8,10},{15,18}};
    cout << "合并后的数组区间为：" << endl;
    vector<vector<int>> ans = merge(integrals);
    for (vector<int> a: ans) {
        cout <<"{" << a[0] << "," << a[1] << "}" << endl;
    }
}
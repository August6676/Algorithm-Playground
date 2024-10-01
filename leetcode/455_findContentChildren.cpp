#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int findContentChildren(vector<int>& g,vector<int>& s) {

    sort(g.begin(),g.end()); // 进行原地排序
    sort(s.begin(),s.end());

    int satisfied = 0;
    int i = 0;

    for (int child :g) {
        while (i < s.size() && child > s[i]) {
            i++;
        }
        if ( i < s.size()) {
            satisfied++;
            i++;
        }
    }
    return satisfied;
}

int main() {
    vector g ={1,3,5,6,7};
    vector s = {2,3,4,5,6};

    cout << "最多能满足 " << findContentChildren(g,s) << " 个孩子" << endl;
}
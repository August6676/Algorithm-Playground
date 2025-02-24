#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 * 使用单调栈的思想
 * 根据柱子的高度找到左右两个边界
 */
int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    stack<int> st;
    heights.push_back(0); // 这是为了保证所有柱子都能出来

    for (int i = 0; i < heights.size();i++) {

        while (!st.empty() && heights[st.top()] > heights[i]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i: i - st.top() - 1;
            maxArea = max(maxArea,height * width);
        }
        st.push(i); // 不要忘记放入元素
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    int maxArea = largestRectangleArea(heights);
    cout << "最大的矩形面积为" << maxArea << endl;
}
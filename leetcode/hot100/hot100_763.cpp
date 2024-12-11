#include <iostream>
#include <vector>
using namespace std;

/*
 * 也是使用贪心算法，和跳跃游戏Ⅱ有些相似
 */
vector<int> partitionLabels(string s) {
 vector lastIndex(26,-1); // 记录该字母最后一次出现的位置

 for (int i = 0; i < s.size(); i++) {
  lastIndex[s[i] - 'a'] = i;
 }

 vector<int> result;
 int start = 0,end = 0;

 for (int i = 0; i < s.size(); i++) {
  end = max(end,lastIndex[s[i] - 'a']); // 更新边界

  if (i == end) { // 达到一段的边界
   result.push_back(end - start + 1);
   start = end + 1;
  }
 }
 return result;
}

int main() {
 string s = "ababcbacadefegdehijhklij";
 vector<int> result = partitionLabels(s);
 for (const auto& num: result) {
  cout << num << " ";
 }
}

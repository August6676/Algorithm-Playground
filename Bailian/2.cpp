#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

/*
* 微博提供了一种便捷的交流平台。一条微博中，可以提及其它用户。例如Lee发出一条微博为：“期末考试顺利 @Kim @Neo”，则Lee提及了Kim和Neo两位用户。
* 我们收集了N(1 < N < 10000)条微博，并已将其中的用户名提取出来，用小于等于100的正整数表示。
* 通过分析这些数据，我们希望发现大家的话题焦点人物，即被提及最多的人（题目保证这样的人有且只有一个），并找出那些提及它的人。
* 输入共两部分：
* 第一部分是微博数量N，1 < N < 10000。
* 第二部分是N条微博，每条微博占一行，表示为：
* 发送者序号a，提及人数k(0 < = k < = 20)，然后是k个被提及者序号b1,b2...bk；
* 其中a和b1,b2...bk均为大于0小于等于100的整数。相邻两个整数之间用单个空格分隔。
* 输出
* 输出分两行：
* 第一行是被提及最多的人的序号；
* 第二行是提及它的人的序号，从小到大输出，相邻两个数之间用单个空格分隔。同一个序号只输出一次。
 */


int main() {
    int n;
    cin >> n;

    unordered_map<int,int> mention_count; // 被@次数
    unordered_map<int,set<int>> mentioners; // 记录 @他的用户 set可以去重！！

    for (int i = 0; i < n;i++) {
        int sender,k;
        cin >> sender >> k;
        for (int i = 0;i < k;i++) {
            int receiver;
            cin >> receiver;
            mention_count[receiver]++;
            mentioners[receiver].insert(sender); // set插入使用insert
        }
    }

    int max_mentions = -1, max_user = -1;
    for (const auto& p:mention_count) { // 哈希表取元素对
        if (p.second > max_mentions) { // x.first x.second
            max_mentions = p.second;
            max_user = p.first;
        }
    }

    cout << max_mentions << endl;
    for (int sender: mentioners[max_user])
        cout << sender << " ";

    return 0;
}

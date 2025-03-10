#include <bitset>
using namespace std;

/*
 * bitset转换成二进制的包
 * 使用方法 bitset<位数> new_name(the num)
 */
int hammingDistance(int x, int y) {
    bitset<32> bitx(x);
    bitset<32> bity(y);

    int count = 0;

    for (int i = 0; i < 32;i++) {
        if (bitx[i] != bity[i])
            count++;
    }

    return count;
}


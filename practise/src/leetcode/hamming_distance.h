#ifndef _INC_HAMMING_DISTANCE_
#define _INC_HAMMING_DISTANCE_

class HammingDistance {
public:
    static void test() {
        auto ret = main(3, 1);
    }

    static int main(int x, int y) {
        int ret = x ^ y;
        int cnt = 0;
        while (ret != 0) {
            ++cnt;
            ret = ret & (ret - 1);
        }
        return cnt;
    }
};

#endif

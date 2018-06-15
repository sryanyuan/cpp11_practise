#ifndef _INC_BINARY_NUMBER_WITH_ALTERNATING_BITS_
#define _INC_BINARY_NUMBER_WITH_ALTERNATING_BITS_

class BinaryNumberWithAlternatingBits {
public:
    static void test() {
        auto ret = main(5);
    }

    static bool main(int n) {
        int pb = -1;
        int mask = 1 << 0;

        while (n != 0) {
            if ((n & mask) == 0) {
                if (pb == -1 || pb == 1) {
                    pb = 0;
                } else {
                    return false;
                }
            } else {
                if (pb == -1 || pb == 0) {
                    pb = 1;
                } else {
                    return false;
                }
            }
            n = n >> 1;
        }
        return true;
    }
};

#endif

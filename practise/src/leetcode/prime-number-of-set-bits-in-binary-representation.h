#ifndef _INC_PRIME_NUMBER_OF_SET_BITS_IN_BINARY_REPRESENTATION_
#define _INC_PRIME_NUMBER_OF_SET_BITS_IN_BINARY_REPRESENTATION_

class PrimeNumberOfSetBitsInBinaryRepresentation {
public:
    static void test() {
        auto ret = main(244, 269);
    }

    static int main(int L, int R) {
        int pcnt = 0;
        for (int i = L; i <= R; i++) {
            int bitCnt = 0;
            int n = i;
            while (n != 0) {
                n &= (n - 1);
                ++bitCnt;
            }
            if (1 == bitCnt) {
                continue;
            }
            // Check if bitCnt is a prime number
            int j = 2;
            for (; j * j <= bitCnt; j++) {
                if (bitCnt % j == 0) {
                    j = 0;
                    break;
                }
            }
            if (j != 0) {
                ++pcnt;
            }
        }
        return pcnt;
    }
};

#endif

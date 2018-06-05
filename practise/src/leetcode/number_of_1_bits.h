#ifndef _INC_NUMBER_OF_1_BITS_
#define _INC_NUMBER_OF_1_BITS_

class NumberOf1Bits {
public:
    static void test() {
        auto ret = main(2441589);
        ret = solution1(2441589);
    }

    static int main(uint32_t n) {
        // Per 4 bits one time
        const int mask = 0x0f;
        int cnt = 0;

        for (int i = 0; i < sizeof(uint32_t) * 8 / 4; i++) {
            int val = n & mask;

            switch (val) {
            case 1:
            case 2:
            case 4:
            case 8:
                {
                    cnt += 1;
                }break;
            case 3:
            case 5:
            case 9:
            case 6:
            case 10:
            case 12:
                {
                    cnt += 2;
                }break;
            case 7:
            case 11:
            case 13:
            case 14:
                {
                    cnt += 3;
                }break;
            case 15:
                {
                    cnt += 4;
                }break;
            }

            n = n >> 4;
        }

        return cnt;
    }

    // Solution of n&(n-1)
    // This operation will erase the left 1 bit per time
    static int solution1(uint32_t n) {
        int cnt = 0;
        while (n != 0) {
            cnt++;
            n &= (n - 1);
        }
        return cnt;
    }
};

#endif

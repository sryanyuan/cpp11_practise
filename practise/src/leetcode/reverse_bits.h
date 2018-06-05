#ifndef _INC_REVERSE_BITS_
#define _INC_REVERSE_BITS_

class ReverseBits {
public:
    static void test() {
        auto ret = main(43261596);
    }

public:
    static uint32_t main(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < sizeof(uint32_t) * 8 / 2; i++) {
            uint32_t lmask = 1 << i;
            uint32_t rmask = 1 << (sizeof(uint32_t) * 8 - 1 - i);
            if ((n & lmask) != 0) {
                ret |= rmask;
            }
            if ((n & rmask) != 0) {
                ret |= lmask;
            }
        }
        return ret;
    }
};

#endif

#ifndef _INC_POWER_OF_TWO_
#define _INC_POWER_OF_TWO_

class PowerOfTwo {
public:
    static void test() {
        auto ret = main(16);
        ret = main(218);
    }

    static bool main(int n) {
        if (n > 0 && (n & (n - 1)) == 0) {
            return true;
        }
        return false;
    }
};

#endif

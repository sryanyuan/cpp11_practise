#ifndef _INC_POWER_OF_FOUR_
#define _INC_POWER_OF_FOUR_

class PowerOfFour {
public:
    static void test() {
        auto ret = uselog(16);
    }

    static bool uselog(int num) {
        // logca = logdc/logda
        if (num <= 0) {
            return false;
        }
        auto ret = log10(num) / log10(4);
        int nret = int(ret);
        return ((long double)(nret) - ret) == 0;
    }

    static bool main(int num) {
        if (num <= 0) {
            return false;
        }
        if ((num & (num - 1)) == 0) {
            // Power of 2
            if ((num - 1) % 3 == 0) {
                return true;
            }
        }
        return false;
    }
};

#endif

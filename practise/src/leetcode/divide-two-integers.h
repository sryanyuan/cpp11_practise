#ifndef _INC_DIVIDE_TWO_INTERGERS_
#define _INC_DIVIDE_TWO_INTERGERS_

#include "_common_all.h"

class DivedeTwoIntegers {
public:
    static void test() {
        auto ret = divide(-2147483648, -1);
        //auto ret = divide(10, 3);
    }

    static int divide(int dividend, int divisor) {
        bool neg = false;
        if (dividend < 0 && divisor > 0) {
            neg = true;
        }
        if (divisor < 0 && dividend > 0) {
            neg = true;
        }
        long long l = dividend;
        if (l < 0) {l = -l;}
        long long r = divisor;
        if (r < 0) {r = -r;}
        long long res = 0;
        long long mval = r;
        long long tms = 1;
        while ((mval << 1) < l) {
            mval = mval << 1;
            tms = tms << 1;
        }
        while (l >= r) {
            while (mval > l) {
                mval = mval >> 1;
                tms = tms >> 1;
            }
            l -= mval;
            res += tms;
            if (!neg) {
                if (res > 0x7fffffff) {
                    return 0x7fffffff;
                }
            } else {
                if (-res < int(0x80000000)) {
                    return 0x7fffffff;
                }
            }
        }
        if (neg) {return -1 * res;}
        return res;
    }
};

#endif

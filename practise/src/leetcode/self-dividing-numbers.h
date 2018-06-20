#ifndef _INC_SELF_DIVIDING_NUMBERS_
#define _INC_SELF_DIVIDING_NUMBERS_

#include "_common_all.h"

class SelfDividingNumbers {
public:
    static vector<int> main(int left, int right) {
        vector<int> rets;
        rets.reserve(right - left + 1);
        for (int i = left; i <= right; i++) {
            if (i < 10) {
                rets.push_back(i);
                continue;
            }
            int n = i;
            while (n != 0) {
                int l = n % 10;
                if (0 == l || i % l != 0) {
                    break;
                }
                n /= 10;
            }
            if (n == 0) {
                rets.push_back(i);
            }
        }
        return rets;
    }
};

#endif

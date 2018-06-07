#ifndef _INC_NTH_DIGIT_
#define _INC_NTH_DIGIT_

#include <string>

class NthDigit {
public:
    static void test() {
        auto ret = main(1000000000);
    }

    static int main(int n) {
        int nBit = 1;
        int nStart = 1;
        int nPreMax = 9;
        long long nEnd = 9;
        int nPreBits = 0;

        while (n > nEnd) {
            ++nBit;
            nPreMax *= 10;
            nStart *= 10;
            nPreBits = nEnd;
            nEnd += (long long)nPreMax * (long long)nBit;
        }

        int offset = n - nPreBits - 1;
        int value = nStart + offset / nBit;
        offset = offset % nBit;
        string sval = std::to_string(value);
        return sval[offset] - '0';
    }
};

#endif

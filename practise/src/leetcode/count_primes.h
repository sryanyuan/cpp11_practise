#ifndef _INC_COUNT_PRIMES_
#define _INC_COUNT_PRIMES_

#include <memory.h>

class CountPrimes {
public:
    static void test() {
        auto ret = main(499979);
    }

    static int main(int n) {
        if (n <= 1) {
            return 0;
        }

        char *pNotPrimFlags = new char[n];
        memset(pNotPrimFlags, 0, n);

        for (long long i = 2; i < n; i++) {
            if (pNotPrimFlags[i] != 0) {
                continue;
            }
            for (long long j = i; j * i < n; j++) {
                pNotPrimFlags[j * i] = 1;
            }
        }

        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (pNotPrimFlags[i] != 0) {
                continue;
            }
            cnt++;
        }

        delete [] pNotPrimFlags;
        pNotPrimFlags = nullptr;

        return cnt;
    }
};

#endif

#ifndef _INC_ARRANGING_COINS_
#define _INC_ARRANGING_COINS_

class ArrangingCoins {
public:
    static void test() {
        auto ret = main(1804289383);
    }

    static int main(int n) {
        int l = 1;
        int r = n;
        if (calc(l) == (long long)n) {
            return l;
        }
        if (calc(r) == (long long)n) {
            return r;
        }
        int mid = l + (r - l) / 2;
        long long val = calc(mid);

        while (l != r) {
            if (val == n) {
                return mid;
            }
            if (r - l == 1) {
                return l;
            }
            if (val > n) {
                r = mid;
            } else {
                l = mid;
            }
            mid = l + (r - l) / 2;
            val = calc(mid);
        }

        return 0;
    }

    static long long calc(int n) {
        long long val = n;
        val = val * (val + 1) / 2;
        return val;
    }
};

#endif

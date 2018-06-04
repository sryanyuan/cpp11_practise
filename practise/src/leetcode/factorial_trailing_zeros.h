#ifndef _INC_FACTORIAL_TRAILING_ZEROS_
#define _INC_FACTORIAL_TRAILING_ZEROS_

class FactorialTrailingZeros {
public:
    static int main(int n) {
        int cnt = 0;
        long long dv = 5;

        while (n >= dv) {
            int v = n / dv;
            cnt += v;
            dv *= 5;
        }

        return cnt;
    }

    static int lowperf(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n / 5);
            n = n / 5;
        }
        return cnt;
    }
};

#endif
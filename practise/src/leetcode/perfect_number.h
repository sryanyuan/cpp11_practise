#ifndef _INC_PERFECT_NUMBER_
#define _INC_PERFECT_NUMBER_

class PerfectNumber {
public:
    static void test() {
        auto ret = main(28);
    }

    static bool main(int num) {
        if (0 == num) {
            return false;
        }

        int sqrtv = sqrt(num);
        int sum = 0;
        for (int i = 1; i <= sqrtv; i++) {
            if (num % i == 0) {
                sum += i;
                int dv = (num / i);
                if (dv != 1 && dv != num && dv != sqrtv) {
                    sum += dv;
                }
            }
        }
        if (sqrtv * sqrtv == num) {
            num += sqrtv;
        }
        return sum == num;
    }
};

#endif

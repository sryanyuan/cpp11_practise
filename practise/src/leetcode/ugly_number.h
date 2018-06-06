#ifndef _INC_UGLY_NUMBER_
#define _INC_UGLY_NUMBER_

class UglyNumber {
public:
    static void test() {
        auto ret = main(8);
    }

    // Slow ??
    static bool main(int num) {
        if (num <= 0) {
            return false;
        }
        static int divNums[] = {2, 3, 5};
        for (int i = 0; i < sizeof(divNums) / sizeof(divNums[0]); i++) {
            while (num % divNums[i] == 0) {
                num /= divNums[i];
            }
        }
        return num == 1;
    }

    // Quick (Beat 100%) ...
    static bool bad(int num) {
        if (num == 1) {
            return true;
        }
        if (num <= 0) {
            return false;
        }
        int n = num;

        static int divNums[] = {2, 3, 5};

        while (true) {
            if (n <= 5) {
                return true;
            }

            bool ok = false;
            for (int i = 0; i < 3; i++) {
                int nv = n % divNums[i];
                if (nv == 0) {
                    n = n / divNums[i];
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                return false;
            }
        }

        return false;
    }
};

#endif

#ifndef _INC_VALID_PERFECT_SQUARE_
#define _INC_VALID_PERFECT_SQUARE_

class ValidPerfectSquare {
public:
    static void test() {
        auto ret = main(808201);
    }

    static bool main(int num) {
        if (num <= 1) {
            return true;
        }

        int si = 1;
        int ei = num;
        int mid = si + (ei - si) / 2;
        long long mid2 = (long long)mid * (long long)mid;

        while (mid2 != num) {
            if (mid2 > num) {
                ei = mid;
            } else {
                si = mid;
            }
            mid = si + (ei - si) / 2;
            mid2 = (long long)mid * (long long)mid;

            if (mid == si) {
                if (ei * ei != num) {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif

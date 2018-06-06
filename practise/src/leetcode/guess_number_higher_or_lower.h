#ifndef _INC_GUESS_NUMBER_HIGHER_OR_LOWER_
#define _INC_GUESS_NUMBER_HIGHER_OR_LOWER_

class GuessNumberHigherOrLower {
public:
    static int guess(int num) {
        int fn = 1;
        if (fn == num) {
            return 0;
        }
        if (fn < num) {
            return -1;
        }
        return 1;
    }

    static void test() {
        auto ret = main(3);
    }

    static int main(int n) {
        int l = 1;
        int r = n;
        int mid = l + (r - l) / 2;
        if (mid == l) {
            if (guess(r) == 0) {
                return r;
            }
        }
        int gr = guess(mid);

        while (gr != 0) {
            if (gr == -1) {
                r = mid;
            } else {
                l = mid;
            }
            mid = l + (r - l) / 2;
            if (mid == l) {
                if (guess(r) == 0) {
                    return r;
                }
            }
            gr = guess(mid);
        }
        return mid;
    }
};

#endif

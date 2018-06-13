#ifndef _INC_SUM_OF_SQUARE_NUMBERS_
#define _INC_SUM_OF_SQUARE_NUMBERS_

class SumOfSquareNumbers {
public:
    static bool main(int c) {
        if (c < 0) {return false;}
        int l = 0;
        int r = sqrt(c);
        while (l <= r) {
            int ret = l * l + r * r;
            if (ret == c) {
                return true;
            } else if (ret > c) {
                r--;
            } else {
                l++;
            }
        }
        return false;
    }
};

#endif

#ifndef _INC_ROTATED_DIGITS_
#define _INC_ROTATED_DIGITS_

#include "_common_all.h"

class RotatedDigits {
public:
    static int main(int N) {
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            int v = i;
            bool r = false;
            while (v != 0) {
                int m = v % 10;
                bool valid = true;
                switch (m)
                {
                case 3:
                case 4:
                case 7:
                    {
                        r = false;
                        valid = false;
                        break;
                    }
                case 2:
                case 5:
                case 6:
                case 9:
                    {
                        r = true;
                        break;
                    }
                default:
                    break;
                }
                if (!valid) {break;}
                v /= 10;
            }
            if (r) {++cnt;}
        }
        return cnt;
    }
};

#endif

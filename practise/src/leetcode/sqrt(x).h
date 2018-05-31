#ifndef _INC_SQRT_X__
#define _INC_SQRT_X__

class SqrtX {
public:
    static int main(int x) {
        if (x == 0) {
            return 0;
        }

        long long li = 1;
        long long ri = x;

        for (;;) {
            if (li == ri) {
                return li;
            }
            long long mi = (li + ri) / 2;
            long long mi2 = mi * mi;
            if (ri - li == 1) {
                return li;
            }
            if (mi2 > x) {
                ri = mi;
            } else if (mi2 < x) {
                li = mi;
            } else {
                return mi;
            }
        }
    }
};

#endif

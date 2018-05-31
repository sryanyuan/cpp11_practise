#ifndef _INC_CLIMBING_STAIRS_
#define _INC_CLIMBING_STAIRS_

class ClimbingStairs {
public:
    static int main(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        int pv1 = 1;
        int pv2 = 2;

        for (int i = 3; i < n; i++) {
            int v = pv1 + pv2;
            pv1 = pv2;
            pv2 = v;
        }

        return pv1 + pv2;
    }
};

#endif

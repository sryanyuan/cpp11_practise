#ifndef _INC_HAPPY_NUMBER_
#define _INC_HAPPY_NUMBER_

#include <set>
using std::set;

class HappyNumber {
public:
    static void test() {
        auto ret = main(18);
    }

    static bool main(int n) {
        if (n <= 0) {
            return false;
        }

        set<int> numsAppear;

        while (n != 1) {
            int ret = 0;
            int val = n;

            while (val != 0) {
                int mod = val % 10;
                ret += mod * mod;
                val /= 10;
            }

            if (numsAppear.count(ret) != 0) {
                return false;
            }
            numsAppear.insert(ret);
            n = ret;
        }

        return true;
    }
};

#endif

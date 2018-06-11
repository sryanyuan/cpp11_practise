#ifndef _INC_NUMBER_COMPLEMENT_
#define _INC_NUMBER_COMPLEMENT_

#include <bitset>
using std::bitset;

class NumberComplement {
public:
    static void test() {
        auto ret = main(1);
    }

    static int main(int num) {
        int out = 0;
        bool start = false;

        for (int i = 31; i >= 0; i--) {
            bool flag = ((num & (1 << i)) != 0);
            if (flag) {start = true;}
            if (!flag && start) {
                out |= (1 << i);
            }
        }
        return out;
    }
};

#endif

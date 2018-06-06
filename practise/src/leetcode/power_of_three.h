#ifndef _INC_POWER_OF_THREE_
#define _INC_POWER_OF_THREE_

class PowerOfThree {
public:
    static bool main(int n) {
        const int maxPowerOfThreeOfInt32 = 1162261467;
        if (n <= 0) {
            return false;
        }
        return (maxPowerOfThreeOfInt32 % n) == 0;
    }
};

#endif

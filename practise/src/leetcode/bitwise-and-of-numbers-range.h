#ifndef _INC_BITWISE_AND_OF_NUMBERS_RANGE_
#define _INC_BITWISE_AND_OF_NUMBERS_RANGE_

/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/

#include "_common_all.h"

class BitwiseAndOfNumbersRange {
public:
    static int rangeBitwiseAnd(int m, int n) {
        int step = 0;
        while (m != n) {
            m = m >> 1;
            n = n >> 1;
            ++step;
        }
        return m << step;
    }
};

#endif

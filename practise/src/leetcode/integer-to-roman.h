#ifndef _INC_INTEGER_TO_ROMAN_
#define _INC_INTEGER_TO_ROMAN_

#include "_common_all.h"

class IntegerToRoman {
public:
    static string intToRoman(int num) {
        string res;
        const char* romanChars[] = {"M", "CM", "D", "CD",
                                    "C", "XC", "L", "XL",
                                    "X", "IX", "V", "IV",
                                    "I"};
        int romanVals[] = {1000, 900, 500, 400,
                            100, 90, 50, 40,
                            10, 9, 5, 4,
                            1};
        int pi = 0;
        while (num != 0) {
            for (int i = pi; i < sizeof(romanVals) / sizeof(romanVals[0]); i++) {
                if (num >= romanVals[i]) {
                    pi = i;
                    num -= romanVals[i];
                    res += romanChars[i];
                    break;
                }
            }
        }
        return res;
    }
};

#endif

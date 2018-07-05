#ifndef _INC_FRACTION_TO_RECURRING_DECIMAL_
#define _INC_FRACTION_TO_RECURRING_DECIMAL_

/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/

#include "_common_all.h"

class FractionToRecurringDecimal {
public:
    static void test() {
        auto res = fractionToDecimal(1, 6);
    }

    static string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string res;
        if ((numerator < 0 && denominator > 0) ||
            (numerator > 0 && denominator < 0)) {
                res = "-";
        }
        long long nu = numerator;
        if (nu < 0) {
            nu = -nu;
        }
        long long de = denominator;
        if (de < 0) {
            de = -de;
        }
        res += std::to_string(nu / de);
        long long rem = nu % de;
        unordered_map<long long, int> decm;
        if (rem != 0) {
            string dec = ".";
            int pos = 0;
            while (rem != 0) {
                auto fnd = decm.find(rem);
                if (fnd != decm.end()) {
                    dec.insert(fnd->second + 1, "(");
                    dec += ")";
                    return res + dec;
                }
                decm.insert(std::make_pair(rem, pos));
                int v = rem * 10 / de;
                pos++;
                rem = rem * 10 % de;
                dec += '0' + v;
            }
            res += dec;
        }
        return res;
    }
};

#endif

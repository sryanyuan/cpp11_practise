#ifndef _INC_MULTIPLY_STRINGS_
#define _INC_MULTIPLY_STRINGS_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generate by leetgen (github.com/sryanyuan/leetgen)
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:


Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:


Input: num1 = "123", num2 = "456"
Output: "56088"


Note:


	The length of both num1 and num2 is < 110.
	Both num1 and num2 contain only digits 0-9.
	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
	You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

class MultiplyStrings {
public:
	static void test() {
		auto ret = multiply("2", "3");
	}

	static string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int dig = 0;
        string res = "0";
        long long nres = 0;

        for (int i = num2.size() - 1; i >= 0; i--) {
            string addnum = mul(num1, num2[i] - '0', dig);
            res = add(res, addnum);
            dig++;
        }
        return res;
	}

    static string mul(string &num, int n, int dig) {
        if (n == 0) {
            return "0";
        }
        string res;
        while (dig > 0) {
            res.push_back('0');
            dig -= 1;
        }
        int carry = 0;
        dig = 1;
        for (int i = num.size() - 1; i >= 0; i--) {
            int val = num[i] - '0';
            val *= n;
            val += carry;
            res.push_back(char(val % 10 + '0'));
            carry = val / 10;
        }
        if (carry != 0) {
            res.push_back(carry + '0');
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    static string add(string &num1, string &num2) {
        if (num2 == "0") {
            return num1;
        }
        string res;
        int offset = 0;
        int carry = 0;
        for (;;) {
            int i1 = num1.size() - 1 - offset;
            int val1 = 0;
            if (i1 >= 0) {
                val1 = num1[i1] - '0';
            }
            int i2 = num2.size() - 1 - offset;
            int val2 = 0;
            if (i2 >= 0) {
                val2 = num2[i2] - '0';
            }
            if (i1 < 0 && i2 < 0) {
                break;
            }
            int val = val1 + val2 + carry;
            res.push_back('0' + (val % 10));
            if (val > 9) {
                carry = 1;
            } else {
                carry = 0;
            }
            offset++;
        }
        if (carry != 0) {
            res.push_back('1');
        }
        
        if (res.empty()) {
            return num1;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

#endif

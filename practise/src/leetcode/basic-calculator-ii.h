#ifndef _INC_BASIC_CALCULATOR_II_
#define _INC_BASIC_CALCULATOR_II_

#include "_common_all.h"

/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

class BasicCalculatorII {
public:
    static void test() {
        auto res = calculate("1-1-1");
    }

    static int calculate(string s) {
        stack<int> opts;
        std::function<void(stack<int>&)> mergeOpt = [](stack<int> &opts) {
            while (!opts.empty()) {
                if (opts.size() == 1) {
                    return;
                }
                int r = opts.top(); opts.pop();
                int op = opts.top(); opts.pop();
                int l = opts.top(); opts.pop();
                int res = 0;
                if (-1 == op) {
                    res = l + r;
                } else if (-2 == op) {
                    res = l - r;
                } else if (-3 == op) {
                    res = l * r;
                } else if (-4 == op) {
                    res = l / r;
                }
                opts.push(res);
            }
        };
        char *numBuf = new char[s.size() + 1];
        int si = 0;
        int prevOpt = 0;
        for (int i = 0; i <= s.size(); i++) {
            int opNum = 0;
            if (i == s.size() || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                numBuf[si++] = 0;
                opts.push(atoi(numBuf));
                si = 0;
                if (prevOpt == -3 || prevOpt == -4) {
                    int r = opts.top(); opts.pop(); opts.pop();
                    int l = opts.top(); opts.pop();
                    int res = 0;
                    if (prevOpt == -3) {
                        res = l * r;
                    } else {
                        res = l / r;
                    }
                    opts.push(res);
                }
                if (s[i] == '+') {
                    mergeOpt(opts);
                    prevOpt = -1;
                    opts.push(prevOpt);
                } else if (s[i] == '-') {
                    mergeOpt(opts);
                    prevOpt = -2;
                    opts.push(prevOpt);
                } else if (s[i] == '*') {
                    prevOpt = -3;
                    opts.push(prevOpt);
                } else if (s[i] == '/') {
                    prevOpt = -4;
                    opts.push(prevOpt);
                }
            } else if (s[i] >= '0' && s[i] <= '9') {
                numBuf[si++] = s[i];
            }
        }
        mergeOpt(opts);
        return opts.top();
    }
};

#endif

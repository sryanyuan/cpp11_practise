#ifndef _INC_DIFFERENT_WAYS_TO_ADD_PARENTHESES_
#define _INC_DIFFERENT_WAYS_TO_ADD_PARENTHESES_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:


Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2

Example 2:


Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10

*/

class DifferentWaysToAddParentheses {
public:
	static void test() {
		auto res = diffWaysToCompute("2*3-4*5");
	}

	static vector<int> diffWaysToCompute(string input) {
        if (input.empty()) {
            return vector<int>();
        }
		vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                // Split strings
                auto lnums = diffWaysToCompute(input.substr(0, i));
                auto rnums = diffWaysToCompute(input.substr(i + 1, input.size() - 1 - (i + 1) + 1));
                for (auto ln : lnums) {
                    for (auto rn : rnums) {
                        int rr = 0;
                        if (input[i] == '+') {
                            rr = ln + rn;
                        } else if (input[i] == '-') {
                            rr = ln - rn;
                        } else if (input[i] == '*') {
                            rr = ln * rn;
                        }
                        res.push_back(rr);
                    }
                }
            }
        }
        if (res.empty()) {
            res.push_back(atoi(input.c_str()));
        }
        return res;
	}
};

#endif

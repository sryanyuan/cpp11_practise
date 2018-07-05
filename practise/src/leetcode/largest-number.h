#ifndef _INC_LARGEST_NUMBER_
#define _INC_LARGEST_NUMBER_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:


Input: [10,2]
Output: "210"

Example 2:


Input: [3,30,34,5,9]
Output: "9534330"


Note: The result may be very large, so you need to return a string instead of an integer.
*/

class LargestNumber {
public:
	static void test() {
		
	}

	static string largestNumber(vector<int>& nums) {
		vector<string> nstrs;
        for (auto v : nums) {
            nstrs.push_back(std::to_string(v));
        }
        int added = 0;
        while (added < nums.size()) {
            vector<int> candidates;
            std::sort(nstrs.begin(), nstrs.end());
            char prevChar = 0;
            int index = 0;
            for (auto &str : nstrs) {
                if (str.empty()) {
                    index++;
                    continue;
                }
                if (0 == prevChar) {
                    prevChar = str[0];
                } else if (str[0] != prevChar) {
                    break;
                }
                candidates.push_back(index);
                index++;
            }
        }
	}
};

#endif

#ifndef _INC_MAJORITY_ELEMENT_II_
#define _INC_MAJORITY_ELEMENT_II_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:


Input: [3,2,3]
Output: [3]

Example 2:


Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/

class MajorityElementIi {
public:
	static void test() {
		
	}

	static vector<int> majorityElement(vector<int>& nums) {
		int n = nums.size() / 3;
        int a = 0, b = 0, ac = 0, bc = 0;
        for (auto v : nums) {
            if (v == a) {
                ++ac;
            } else if (v == b) {
                ++bc;
            } else if (ac == 0) {
                ac = 1; a = v;
            } else if (bc == 0) {
                bc = 1; b = v;
            } else {
                --ac; --bc;
            }
        }
        ac = bc = 0;
        for (auto v : nums) {
            if (v == a) {
                ++ac;
            } else if (v == b) {
                ++bc;
            }
        }
        vector<int> res;
        if (ac > n) {res.push_back(a);}
        if (bc > n) {res.push_back(b);}
        return res;
	}
};

#endif
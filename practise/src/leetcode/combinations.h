#ifndef _INC_COMBINATIONS_
#define _INC_COMBINATIONS_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:


Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

class Combinations {
public:
	static void test() {
		
	}

	static vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> nums;
		cb(1, n, k, res, nums);
        return res;
	}

    static void cb(int s, int n, int k, vector<vector<int>> &res, vector<int> &nums) {
        if (nums.size() == k) {
            res.push_back(nums);
            return;
        }
        for (int i = s; i <= n; i++) {
            nums.push_back(i);
            cb(i + 1, n, k, res, nums);
            nums.pop_back();
        }
    }
};

#endif
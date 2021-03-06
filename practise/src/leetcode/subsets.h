#ifndef _INC_SUBSETS_
#define _INC_SUBSETS_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:


Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Subsets {
public:
	static void test() {
		
	}

	static vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
        vector<int> tmp;
        dfs(0, nums.size() - 1, nums, tmp, res);
        res.push_back(vector<int>());
        return res;
	}

    static void dfs(int si, int ei, vector<int> &nums, vector<int> &tmp, vector<vector<int>> &res) {
        if (tmp.size() > 0) {
            res.push_back(tmp);
        }
        for (int i = si; i <= ei; i++) {
            tmp.push_back(nums[i]);
            dfs(i + 1, ei, nums, tmp, res);
            tmp.pop_back();
        }
    }
};

#endif

#ifndef _INC_COMBINATION_SUM_
#define _INC_COMBINATION_SUM_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generate by leetgen (github.com/sryanyuan/leetgen)
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:


	All numbers (including target) will be positive integers.
	The solution set must not contain duplicate combinations.


Example 1:


Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]


Example 2:


Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

*/

class CombinationSum {
public:
	static void test() {
	    vector<int> nums;
        nums.push_back(2);
        nums.push_back(3);
        nums.push_back(6);
        nums.push_back(7);
        int target = 7;
        auto ret = combinationSum(nums, target);
	}

	static vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	    vector<vector<int>> rets;
        vector<int> mret;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, mret, rets);
        return rets;
	}

    static void dfs(vector<int>& candidates, 
        int target, 
        int index, 
        vector<int>& mret, 
        vector<vector<int>> &rets) {
            if (index >= candidates.size()) {
                return;
            }
            if (target == 0) {
                rets.push_back(vector<int>(mret));
                return;
            }
            if (candidates[index] > target) {
                return;
            }

            for (int i = index; i < candidates.size(); i++) {
                if (i != index && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                mret.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i, mret, rets);
                mret.pop_back();
            }
    }
};

#endif

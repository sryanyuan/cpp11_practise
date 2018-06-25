#ifndef _INC_COMBINATION_SUM_II_
#define _INC_COMBINATION_SUM_II_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generate by leetgen (github.com/sryanyuan/leetgen)
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:


	All numbers (including target) will be positive integers.
	The solution set must not contain duplicate combinations.


Example 1:


Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]


Example 2:


Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

*/

class CombinationSumIi {
public:
	static void test() {
		
	}

	static vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> rets;
        vector<int> mret;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, mret, rets);
        return rets;
	}

    static void dfs(vector<int>& candidates, int target, int index, vector<int> &mret, vector<vector<int>> &rets) {
        if (target == 0) {
            rets.push_back(vector<int>(mret));
            return;
        }
        if (index >= candidates.size()) {
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
            dfs(candidates, target - candidates[i], i + 1, mret, rets);
            mret.pop_back();
        }
    }
};

#endif

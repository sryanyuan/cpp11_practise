#ifndef _INC_PERMUTATIONS_
#define _INC_PERMUTATIONS_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generate by leetgen (github.com/sryanyuan/leetgen)
Given a collection of distinct integers, return all possible permutations.

Example:


Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

class Permutations {
public:
	static void test() {
		
	}

	static vector<vector<int>> permute(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
		vector<vector<int>> res;
        res.push_back(nums);
        int cnt = 1;
        for (int i = nums.size(); i >= 1; i--) {
            cnt *= i;
        }
        cnt--;
        for (int i = 0; i < cnt; i++) {
            vector<int> src;
            if (!res.empty()) {
                src = res.back();
            } else {
                src = nums;
            }
            int index = 0;
            for (int j = src.size() - 1; j >= 1; j--) {
                if (src[j - 1] < src[j]) {
                    for (int k = src.size() - 1; k >= j; k--) {
                        if (src[k] > src[j - 1]) {
                            std::swap(src[k], src[j - 1]);
                            break;
                        }
                    }
                    std::reverse(src.begin() + j, src.end());
                    break;
                }
            }
            res.push_back(std::move(src));
        }
        return res;
	}
};

#endif

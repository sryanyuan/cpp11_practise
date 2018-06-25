#ifndef _INC_PERMUTATIONS_II_
#define _INC_PERMUTATIONS_II_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generate by leetgen (github.com/sryanyuan/leetgen)
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:


Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

class PermutationsIi {
public:
	static void test() {
		
	}

	static vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back(nums);

        for (;;) {
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
            if (src == res.back()) {
                break;
            }
            res.push_back(std::move(src));
        }
        return res;
	}
};

#endif

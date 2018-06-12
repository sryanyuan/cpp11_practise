#ifndef _INC_K_DIFF_PAIRS_IN_AN_ARRAY_
#define _INC_K_DIFF_PAIRS_IN_AN_ARRAY_

#include <vector>
using std::vector;
#include <algorithm>

class KDiffPairsInAnArray {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(1);
        nums.push_back(1);
        nums.push_back(1);
        nums.push_back(1);
        nums.push_back(1);
        auto ret = main(nums, 0);
    }

    static int main(vector<int>& nums, int k) {
        if (nums.size() <= 1) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int i = 0, j = 1, cnt = 0;
        while (i < nums.size() && j < nums.size()) {
            int diff = abs(nums[i] - nums[j]);
            if (diff > k) {
                i++;
            } else if (diff < k) {
                j++;
            } else {
                cnt++;
                // Move
                int pj = nums[j];
                int pi = nums[i];
                for (j; j < nums.size(); j++) {
                    if (nums[j] != pj) {
                        break;
                    }
                }
                for (i; i < nums.size(); i++) {
                    if (nums[i] != pi) {
                        break;
                    }
                }
            }
            if (i == j) {
                j++;
            }
        }
        return cnt;
    }
};

#endif

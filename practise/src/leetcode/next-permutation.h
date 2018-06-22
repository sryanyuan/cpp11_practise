#ifndef _INC_NEXT_PERMUTATION_
#define _INC_NEXT_PERMUTATION_

#include "_common_all.h"

class NextPermutation {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(3);
        nextPermutation(nums);
    }

    static void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                for (int j = nums.size() - 1; j >= i + 1; j--) {
                    if (nums[j] > nums[i]) {
                        std::swap(nums[j], nums[i]);
                        break;
                    }
                }
                std::reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        return std::reverse(nums.begin(), nums.end());
    }
};

#endif

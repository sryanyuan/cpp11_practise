#ifndef _INC_NON_DECREASING_ARRAY_
#define _INC_NON_DECREASING_ARRAY_

#include "_common_all.h"

class NonDecreasingArray {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(4);
        nums.push_back(2);
        nums.push_back(3);
        auto ret = main(nums);
    }

    static bool main(vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }
        int cnt = 0;
        int premax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (premax > nums[i]) {
                ++cnt;
                if (cnt > 1) {
                    return false;
                }
                if (i - 1 == 0 || nums[i - 2] <= nums[i]) {
                    if (premax == nums[i - 1]) {
                        premax = nums[i];
                    }
                }
            } else {
                premax = nums[i];
            }
        }
        return true;
    }
};

#endif

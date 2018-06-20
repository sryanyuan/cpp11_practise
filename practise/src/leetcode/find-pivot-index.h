#ifndef _INC_FIND_PIVOT_INDEX_
#define _INC_FIND_PIVOT_INDEX_

#include "_common_all.h"

class FindPivotIndex {
public:
    static void test() {
        int num[] = {-1, -1, -1, 0, 1, 1};
        vector<int> nums;
        for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++) {
            nums.push_back(num[i]);
        }
        auto ret = main(nums);
    }

    static int main(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1;
        }
        int ls = 0;
        int rs = 0;
        for (int i = nums.size() - 1; i >= 1; i--) {
            rs += nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (ls == rs) {
                return i;
            }
            if (i != nums.size() - 1) {
                ls += nums[i];
                rs -= nums[i + 1];
            }
        }

        return -1;
    }
};

#endif

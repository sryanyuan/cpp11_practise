#ifndef _INC_THIRD_MAXIMUM_NUMBER_
#define _INC_THIRD_MAXIMUM_NUMBER_

#include <vector>
using std::vector;

class ThirdMaximumNumber {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(-2147483648);
        auto ret = main(nums);
    }

    // O(n) , no sort
    static int main(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums[0];
        }
        if (nums.size() <= 2) {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }

        long ascorder[3] = {LONG_MIN, LONG_MIN, LONG_MIN};
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > ascorder[2]) {
                int tmp = ascorder[2];
                ascorder[2] = nums[i];
                int tmp1 = ascorder[1];
                ascorder[1] = tmp;
                ascorder[0] = tmp1;
                cnt++;
            } else if (nums[i] > ascorder[1] && nums[i] < ascorder[2]) {
                int tmp = ascorder[1];
                ascorder[1] = nums[i];
                ascorder[0] = tmp;
                cnt++;
            } else if (nums[i] > ascorder[0] && nums[i] < ascorder[1]) {
                ascorder[0] = nums[i];
                cnt++;
            }
        }

        if (cnt < 3) {
            return ascorder[2];
        }
        return ascorder[0];
    }
};

#endif

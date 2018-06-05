#ifndef _INC_HOUSE_ROBBER_
#define _INC_HOUSE_ROBBER_

#include <vector>
using std::vector;

class HouseRobber {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(2);
        nums.push_back(7);
        nums.push_back(9);
        nums.push_back(3);
        nums.push_back(1);
        auto ret = main(nums);
    }

    static int main(vector<int>& nums) {
        // Dynamic planning
        // Max result of index i is the max(prev2 + nums[i], prev)
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        int ret = nums[0];
        int pre2 = 0;
        int pre = ret;

        for (int i = 1; i < nums.size(); i++) {
            int n = pre2 + nums[i];
            if (n < pre) {
                n = pre;
            }
            if (n > ret) {
                ret = n;
            }
            pre2 = pre;
            pre = n;
        }

        return ret;
    }
};

#endif

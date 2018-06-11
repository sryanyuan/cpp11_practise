#ifndef _INC_MAX_CONSECUTIVE_ONES_
#define _INC_MAX_CONSECUTIVE_ONES_

#include <vector>
using std::vector;

class MaxConsecutiveOnes {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(1);
        nums.push_back(1);
        nums.push_back(0);
        nums.push_back(1);
        nums.push_back(1);
        nums.push_back(1);
        auto ret = main(nums);
    }

    static int main(vector<int>& nums) {
        if (nums.empty()) {return 0;}
        int cnt = 0;
        int mcnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                if (cnt > mcnt) {
                    mcnt = cnt;
                }
                cnt = 0;
            }
        }
        if (cnt > mcnt) {
            mcnt = cnt;
        }
        return mcnt;
    }
};

#endif

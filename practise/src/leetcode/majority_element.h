#ifndef _INC_MAJORITY_ELEMENT_
#define _INC_MAJORITY_ELEMENT_

#include <vector>
using std::vector;

class MajorityElement {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(3);
        nums.push_back(2);
        nums.push_back(3);
        auto ret = main(nums);
    }

    static int main(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (0 == count) {
                candidate = nums[i];
                count++;
            } else {
                if (candidate == nums[i]) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        return candidate;
    }
};

#endif

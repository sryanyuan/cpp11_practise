#ifndef _INC_ROTATE_ARRAY_
#define _INC_ROTATE_ARRAY_

#include <vector>
using std::vector;
#include <algorithm>

class RotateArray {
public:
    static void main(vector<int>& nums, int k) {
        if (nums.size() <= 1) {
            return;
        }
        k = k % nums.size();
        if (0 == k) {
            return;
        }

        int ln = nums.size() - k;
        int rn = k;
        std::reverse(nums.begin(), nums.begin() + ln);
        std::reverse(nums.begin() + ln, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};

#endif

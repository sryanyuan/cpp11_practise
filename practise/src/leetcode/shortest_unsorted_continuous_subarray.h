#ifndef _INC_UNSORTED_CONTINUOUS_SUBARRAY_
#define _INC_UNSORTED_CONTINUOUS_SUBARRAY_

#include <vector>
using std::vector;
#include <algorithm>

class ShortestUnsortedContinuousSubarray {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(2);
        nums.push_back(6);
        nums.push_back(4);
        nums.push_back(8);
        nums.push_back(10);
        nums.push_back(9);
        nums.push_back(15);
        auto ret = usort(nums);
    }

    static int usort(vector<int>& nums) {
        if (nums.size() <= 1) {return 0;}
        vector<int> ncp = nums;
        std::sort(ncp.begin(), ncp.end());
        int si = 0;
        int ei = nums.size() - 1;

        int i = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != ncp[i]) {
                si = i;
                break;
            }
        }
        if (i >= nums.size()) {return 0;}

        i = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] != ncp[i]) {
                ei = i;
                break;
            }
        }

        return ei - si + 1;
    }

    static int main(vector<int>& nums) {
        if (nums.size() <= 1) {return 0;}
        bool asc = true;
        int si = 0;
        int ei = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            bool valid = true;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {break;}
            si = i + 1;
        }
        if (si >= nums.size()) {
            return 0;
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            bool valid = true;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] < nums[j]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {break;}
            ei = i - 1;
        }
        if (ei <= 0) {return 0;}
        return (ei - si) + 1;
    }
};

#endif

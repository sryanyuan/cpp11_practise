#ifndef _INC_MOVE_ZEROS_
#define _INC_MOVE_ZEROS_

#include <vector>
using std::vector;

class MoveZeros {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(0);
        nums.push_back(1);
        nums.push_back(0);
        nums.push_back(3);
        nums.push_back(12);
        main(nums);
    }

    static void main(vector<int>& nums) {
        int nonZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZero++] = nums[i];
            }
        }
        for (nonZero; nonZero < nums.size(); nonZero++) {
            nums[nonZero] = 0;
        }
    }

    static void bad(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                continue;
            }
            // Finding the next non zero number and swap
            bool found = false;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == 0) {
                    continue;
                }
                nums[i] = nums[j];
                nums[j] = 0;
                found = true;
                break;
            }
            if (!found) {
                break;
            }
        }
    }
};

#endif

#ifndef _INC_MAXIMUM_PRODUCT_OF_THREE_NUMBERS_
#define _INC_MAXIMUM_PRODUCT_OF_THREE_NUMBERS_

#include "_common_all.h"

class MaximumProductOfThreeNumbers {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(-1);
        nums.push_back(-2);
        nums.push_back(-3);
        auto ret = main(nums);
    }

    static int main(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums[nums.size() - 1], nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
    }

    static bool pushb(int (&arr)[3], int val) {
        for (int i = sizeof(arr) / sizeof(arr[0]) - 1; i >= 0; i--) {
            if (arr[i] == INT_MAX || val > arr[i]) {
                for (int j = 0; j <= i; j++) {
                    if (j == i) {
                        arr[j] = val;
                    } else {
                        arr[j] = arr[j + 1];
                    }
                }
                return true;
            }
        }
        return false;
    }

    static bool pushs(int (&arr)[2], int val) {
        for (int i = sizeof(arr) / sizeof(arr[0]) - 1; i >= 0; i--) {
            if (arr[i] == INT_MIN || val < arr[i]) {
                for (int j = 0; j <= i; j++) {
                    if (j == i) {
                        arr[j] = val;
                    } else {
                        arr[j] = arr[j + 1];
                    }
                }
                return true;
            }
        }
        return false;
    }
};

#endif

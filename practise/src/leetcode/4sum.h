#ifndef _INC_4SUM_
#define _INC_4SUM_

#include "_common_all.h"

class FourSum {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(-5);
        nums.push_back(-4);
        nums.push_back(-3);
        nums.push_back(3);
        nums.push_back(3);
        nums.push_back(5);
        auto ret = fourSum(nums, -11);
    }

    static vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return vector<vector<int>>();
        }
        vector<vector<int>> res;
        vector<int> poses;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++) {
            if (nums[i] > 0 && nums[i] > target) {
                break;
            }
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target3 = target - nums[i];

            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (nums[j] > 0 && nums[j] > target3) {
                    break;
                }
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int target2 = target3 - nums[j];
                int l = j + 1;
                int r = nums.size() - 1;
                while (r > l) {
                    int sum = nums[l] + nums[r];
                    bool ml = false, mr = false;
                    if (sum == target2) {
                        poses.push_back(nums[i]);
                        poses.push_back(nums[j]);
                        poses.push_back(nums[l]);
                        poses.push_back(nums[r]);
                        res.push_back(std::move(poses));
                        ml = true; mr = true;
                    } else if (sum > target2) {
                        mr = true;
                    } else {
                        ml = true;
                    }
                    if (ml) {
                        int pv = nums[l];
                        while (r > l) {
                            if (pv != nums[l]) {
                                break;
                            }
                            l++;
                        }
                    }
                    if (mr) {
                        int pv = nums[r];
                        while (r > l) {
                            if (pv != nums[r]) {
                                break;
                            }
                            r--;
                        }
                    }
                }
            }
        }
        return res;
    }
};

#endif

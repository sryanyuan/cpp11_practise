#ifndef _INC_3SUM_
#define _INC_3SUM_

#include "_common_all.h"

class ThreeSum {
public:
    static void test() {
        vector<int> nums;
        int na[] = {-1,0,1,2,-1,-4};
        for (int i = 0; i < sizeof(na) / sizeof(na[0]); i++) {
            nums.push_back(na[i]);
        }
        auto ret = threeSum(nums);
    }

    static vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return vector<vector<int>>();
        }
        vector<vector<int>> res;
        vector<int> pos;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int fnum = -1 * nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                bool ml = false, mr = false;
                if (sum == fnum) {
                    pos.push_back(nums[i]);
                    pos.push_back(nums[l]);
                    pos.push_back(nums[r]);
                    res.push_back(std::move(pos));
                    ml = true; mr = true;
                } else if (sum > fnum) {
                    mr = true;
                } else {
                    ml = true;
                }
                if (mr) {
                    int pv = nums[r];
                    while (r > l) {
                        if (nums[r] != pv) {
                            break;
                        }
                        r--;
                    }
                }
                if (ml) {
                    int pv = nums[l];
                    while (r > l) {
                        if (nums[l] != pv) {
                            break;
                        }
                        l++;
                    }
                }
            }
        }
        return res;
    }
};

#endif

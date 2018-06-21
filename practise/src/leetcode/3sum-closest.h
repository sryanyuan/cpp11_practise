#ifndef _INC_3SUM_CLOSEST_
#define _INC_3SUM_CLOSEST_

#include "_common_all.h"

class ThreeSumClosest {
public:
    static void test() {
        vector<int> nums;
        int na[] = {0, 2, 1, -3};
        for (int i = 0; i < sizeof(na) / sizeof(na[0]); i++) {
            nums.push_back(na[i]);
        }
        auto ret = threeSumClosest(nums, 1);
    }

    static int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }
        int *mt = nullptr;
        std::sort(nums.begin(), nums.end());
        bool lt = false;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > target) {
                if (lt) {
                    break;
                }
                lt = true;
            }
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int fnum = target - nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                int nt = sum + nums[i];
                if (mt == nullptr || abs(nt - target) < abs(*mt - target)) {
                    if (nullptr == mt) {
                        mt = new int;
                    }
                    *mt = nt;
                }
                bool ml = false, mr = false;
                if (sum == fnum) {
                    return target;
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
        int res = *mt;
        delete mt;
        return res;
    }
};

#endif

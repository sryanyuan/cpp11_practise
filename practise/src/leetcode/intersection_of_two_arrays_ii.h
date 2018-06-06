#ifndef _INC_INTERSECTION_OF_TWO_ARRAYS_
#define _INC_INTERSECTION_OF_TWO_ARRAYS_II_

#include <vector>
using std::vector;
#include <algorithm>

class IntersectionOfTwoArraysII {
public:
    static vector<int> main(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> rets;

        int i = 0, j = 0;
        for (; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] == nums2[j]) {
                rets.push_back(nums1[i]);
                i++; j++;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                ++i;
            }
        }

        return rets;
    }
};

#endif

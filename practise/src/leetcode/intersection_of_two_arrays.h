#ifndef _INC_INTERSECTION_OF_TWO_ARRAYS_
#define _INC_INTERSECTION_OF_TWO_ARRAYS_

#include <vector>
using std::vector;
#include <unordered_set>
using std::unordered_set;

class IntersectionOfTwoArrays {
public:
    static vector<int> main(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ns1(nums1.begin(), nums1.end());
        vector<int> rets;

        for (auto v : nums2) {
            if (ns1.erase(v)) {
                rets.push_back(v);
            }
        }

        return rets;
    }
};

#endif

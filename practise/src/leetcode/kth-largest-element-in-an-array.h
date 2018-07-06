#ifndef _INC_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_
#define _INC_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note: 
You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.
*/

#include "_common_all.h"

class KthLargestElementInAnArray {
public:
    static int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.rbegin(), nums.rend());
        return nums[k - 1];
    }
};

#endif

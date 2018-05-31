#ifndef _INC_MERGE_SORTED_ARRAY_
#define _INC_MERGE_SORTED_ARRAY_

/*
https://leetcode.com/problems/merge-sorted-array/description/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

#include <vector>
using std::vector;

class MergeSortedArray {
public:
    static void main(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ii = m + n - 1;
        int si = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (si < 0) {
                // nums1 do not have any element
                nums1[ii--] = nums2[i];
                continue;
            }

            if (nums2[i] >= nums1[si]) {
                nums1[ii--] = nums2[i];
            } else {
                nums1[ii--] = nums1[si];
                si--;
                i++;
            }
        }
    }
};

#endif

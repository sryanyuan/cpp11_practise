#ifndef _INC_SEARCH_IN_ROTATED_SORTED_ARRAY_
#define _INC_SEARCH_IN_ROTATED_SORTED_ARRAY_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generate by leetgen (github.com/sryanyuan/leetgen)
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm&#39;s runtime complexity must be in the order of&nbsp;O(log&nbsp;n).

Example 1:


Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4


Example 2:


Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class SearchInRotatedSortedArray {
public:
	static void test() {
	
	}

	static int search(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			int midv = 0;
			if (nums[mid] < nums[0] == target < nums[0]) {
				midv = nums[mid];
			}
			else {
				if (nums[mid] >= nums[0]) {
					midv = INT_MIN;
				}
				else {
					midv = INT_MAX;
				}
			}
			if (midv < target) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		return -1;
	}
};

#endif

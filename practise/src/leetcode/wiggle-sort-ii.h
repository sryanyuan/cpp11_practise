#ifndef _INC_WIGGLE_SORT_II_
#define _INC_WIGGLE_SORT_II_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:


Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].

Example 2:


Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

class WiggleSortIi {
public:
	static void test() {
		
	}

	static void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        vector<int> tmp = nums;
		std::sort(tmp.begin(), tmp.end());
        int mid = (nums.size()  - 1) / 2;
        int tail = nums.size() - 1;
        for (int i = 0; i < nums.size(); i += 2) {
            nums[i] = tmp[mid];
            if (tail != (nums.size() - 1) / 2) {
                nums[i + 1] = tmp[tail];
            }
            --mid; --tail;
        }
	}
};

#endif

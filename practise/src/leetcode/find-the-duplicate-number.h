#ifndef _INC_FIND_THE_DUPLICATE_NUMBER_
#define _INC_FIND_THE_DUPLICATE_NUMBER_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:


Input: [1,3,4,2,2]
Output: 2


Example 2:


Input: [3,1,3,4,2]
Output: 3

Note:


	You must not modify the array (assume the array is read only).
	You must use only constant, O(1) extra space.
	Your runtime complexity should be less than O(n2).
	There is only one duplicate number in the array, but it could be repeated more than once.

*/

class FindTheDuplicateNumber {
public:
	static void test() {
		int ar[] = {1,3,4,2,2};
        vector<int> nums(ar, ar + sizeof(ar) / sizeof(ar[0]));
        auto res = findDuplicate(nums);
	}

	static int findDuplicate(vector<int>& nums) {
		int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow <= fast);
        slow = nums[0];
        while (nums[slow] != nums[fast]) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return nums[slow];
	}
};

#endif

#ifndef _INC_MINIMUM_SIZE_SUBARRAY_SUM_
#define _INC_MINIMUM_SIZE_SUBARRAY_SUM_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 


Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

Follow up:

If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/

class MinimumSizeSubarraySum {
public:
	static void test() {
		int ar[] = {2,3,1,2,4,3};
        vector<int> nums(ar, ar + sizeof(ar) / sizeof(ar[0]));
        auto res = minSubArrayLen(7, nums);
	}

	static int minSubArrayLen(int s, vector<int>& nums) {
		int si = 0;
        int psum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            psum += nums[i];
            if (psum >= s) {
                int sum = psum;
                for (int j = si; j < i; j++) {
                    if (sum - nums[j] >= s) {
                        si++;
                        sum -= nums[j];
                    } else {
                        break;
                    }
                }
                psum = sum;
                if (i - si + 1 < res || 0 == res) {
                    res = i - si + 1;
                }
            }
        }
        return res;
	}
};

#endif
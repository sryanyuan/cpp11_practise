#ifndef _INC_LONGEST_HARMONIOUS_SUBSEQUENCE_
#define _INC_LONGEST_HARMONIOUS_SUBSEQUENCE_

#include <vector>
using std::vector;
#include <algorithm>

class LongestHarmoniousSubsequence {
public:
	static void test() {
		vector<int> nums;
		nums.push_back(1);
		nums.push_back(3);
		nums.push_back(2);
		nums.push_back(2);
		nums.push_back(5);
		nums.push_back(2);
		nums.push_back(3);
		nums.push_back(7);
		auto ret = main(nums);
	}
    static int main(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        vector<int> cnts;
        int pre = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == pre) {
                ++cnt;
            } else {
                cnts.push_back(pre);
                cnts.push_back(cnt);
                pre = nums[i];
                cnt = 1;
            }
        }
        if (cnt != 0) {
            cnts.push_back(nums[nums.size() - 1]);
            cnts.push_back(cnt);
        }
        pre = cnts[0];
        cnt = cnts[1];
        int longest = 0;

        for (int i = 2; i < cnts.size(); i += 2) {
            if (cnts[i] - pre == 1) {
                int curlong = cnt + cnts[i + 1];
                if (curlong > longest) {
                    longest = curlong;
                }
            }
            pre = cnts[i];
            cnt = cnts[i + 1];
        }
        return longest;
    }
};

#endif

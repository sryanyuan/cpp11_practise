#ifndef _INC_DEGREE_OF_AN_ARRAY_
#define _INC_DEGREE_OF_AN_ARRAY_

#include "_common_all.h"

class DegreeOfAnArray {
public:
	struct GroupInfo {
		int start;
		int end;
		int count;
		int value;

		GroupInfo(int v, int i) {
			start = end = i;
			count = 1;
			value = v;
		}
	};

	static void test() {
		vector<int> nums;
		nums.push_back(1);
		nums.push_back(2);
		nums.push_back(2);
		nums.push_back(3);
		nums.push_back(1);
		nums.push_back(4);
		nums.push_back(2);
		auto ret = main(nums);
	}

	static int main(vector<int>& nums) {
		unordered_map<int, GroupInfo*> dmap;
		dmap.insert(std::make_pair(nums[0], new GroupInfo(nums[0], 0)));

		for (int i = 1; i < nums.size(); i++) {
			auto fnd = dmap.find(nums[i]);
			if (fnd == dmap.end()) {
				dmap.insert(std::make_pair(nums[i], new GroupInfo(nums[i], i)));
			}
			else {
				fnd->second->count++;
				fnd->second->end = i;
			}
		}

		int mv = -1;
		int md = 50000;
		for (auto &gi : dmap) {
			int degree = gi.second->count;
			if (degree > mv || (degree == mv && gi.second->end - gi.second->start + 1 < md)) {
				mv = gi.second->count;
				md = gi.second->end - gi.second->start + 1;
			}
		}
		return md;
	}
};

#endif

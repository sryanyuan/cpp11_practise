#ifndef _INC_RELATIVE_RANKS_
#define _INC_RELATIVE_RANKS_

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
#include <unordered_map>
using std::unordered_map;

class RelativeRanks {
public:
    static vector<string> main(vector<int>& nums) {
        static const char* medals[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
		vector<int> ranknums = nums;
		std::sort(ranknums.rbegin(), ranknums.rend());
		unordered_map<int, int> rank;
		for (int i = 0; i < ranknums.size(); i++) {
			rank.insert(std::make_pair(ranknums[i], i));
		}

		vector<string> rets;
		rets.reserve(nums.size());

		for (int i = 0; i < nums.size(); i++) {
			auto fnd = rank.find(nums[i]);
			int rankv = fnd->second;
			if (0 == rankv) {
				rets.push_back(medals[0]);
			}
			else if (1 == rankv) {
				rets.push_back(medals[1]);
			}
			else if (2 == rankv) {
				rets.push_back(medals[2]);
			}
			else {
				rets.push_back(std::to_string(rankv + 1));
			}
		}
		return rets;
    }
};

#endif

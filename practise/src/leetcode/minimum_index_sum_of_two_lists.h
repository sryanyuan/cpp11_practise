#ifndef _INC_MINIMUM_INDEX_SUM_OF_TWO_LISTS_
#define _INC_MINIMUM_INDEX_SUM_OF_TWO_LISTS_

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;

class MinimumIndexSumOfTwoLists {
public:
	static void test() {
		vector<string> l1;
		l1.push_back("KFC");
		vector<string> l2;
		l2.push_back("KFC");
		auto ret = main(l1, l2);
	}

	static vector<string> main(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, int> list1m;
		int index = 0;
		for (auto &k : list1) {
			list1m.insert(std::make_pair(k, index));
			index++;
		}
		vector<string> rets;
		index = 0;
		int mindex = list1.size() + list2.size();
		for (auto &k : list2) {
			auto fnd = list1m.find(k);
			index++;
			if (fnd == list1m.end()) {
				continue;
			}
			int nindex = fnd->second + index;
			if (nindex <= mindex) {
				if (nindex != mindex) {
					rets.clear();
				}
				rets.push_back(k);
				mindex = nindex;
			}
		}
		return rets;
	}
};

#endif

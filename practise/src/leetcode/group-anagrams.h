#ifndef _INC_GROUP_ANAGRAMS_
#define _INC_GROUP_ANAGRAMS_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generate by leetgen (github.com/sryanyuan/leetgen)
Given an array of strings, group anagrams together.

Example:


Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:


	All inputs will be in lowercase.
	The order of your output does not matter.

*/

class GroupAnagrams {
public:
	static void test() {
		vector<string> strs;
        strs.push_back("eat");
        strs.push_back("tea");
        strs.push_back("tan");
        strs.push_back("ate");
        strs.push_back("nat");
        strs.push_back("bat");
        auto ret = groupAnagrams(strs);
	}

	static vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> smap;
        for (auto &str : strs) {
            string sstr = str;
            std::sort(sstr.begin(), sstr.end());
            auto fnd = smap.find(sstr);
            if (fnd == smap.end()) {
                vector<string> vals;
                vals.push_back(str);
                smap.insert(std::make_pair(sstr, std::move(vals)));
            } else {
                fnd->second.push_back(str);
            }
        }
        vector<vector<string>> res;
        for (auto &pa : smap) {
            res.push_back(std::move(pa.second));
        }
        return res;
	}
};

#endif

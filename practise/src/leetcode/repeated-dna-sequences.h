#ifndef _INC_REPEATED_DNA_SEQUENCES_
#define _INC_REPEATED_DNA_SEQUENCES_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:


Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]

*/

class RepeatedDnaSequences {
public:
	static void test() {
		
	}

	static vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string, int> dnas;
        vector<string> res;
        for (int i = 0; i < s.size(); i++) {
            int left = s.size() - i;
            if (left < 10) {
                break;
            }
            string sub = s.substr(i, 10);
            auto fnd = dnas.find(sub);
            if (fnd == dnas.end()) {
                dnas.insert(std::make_pair(std::move(sub), 1));
            } else {
                ++fnd->second;
            }
        }
        for (auto &it : dnas) {
            if (it.second > 1) {
                res.push_back(std::move(it.first));
            }
        }
        return res;
	}
};

#endif

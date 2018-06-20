#ifndef _INC_LONGEST_WORD_IN_DICTIONARY_
#define _INC_LONGEST_WORD_IN_DICTIONARY_

#include "_common_all.h"

class LongestWordInDictionary {
public:
    static void test() {
        const char* wptrs[] = {"ts","e","x","pbhj","opto","xhigy","erikz","pbh","opt","erikzb","eri","erik","xlye","xhig","optoj","optoje","xly","pb","xhi","x","o"};
        vector<string> words;
        for (int i = 0; i < sizeof(wptrs) / sizeof(wptrs[0]); i++) {
            words.push_back(wptrs[i]);
        }
        auto ret = setmain(words);
    }

    static string setmain(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& l, const string& r) -> bool {
            if (r.size() != l.size()) {return r.size() > l.size(); }
            return r > l;
        });
        unordered_set<string> sset;
        string ret;
        for (auto &str : words) {
            if (str.size() == 1 || sset.count(str.substr(0, str.size() - 1)) != 0) {
                sset.insert(str);
                if (str.size() > ret.size()) {
                    ret = str;
                }
            }
        }
        return ret;
    }

	static string main(vector<string>& words) {
		std::sort(words.begin(), words.end(), [](const string& l, const string& r) -> bool {
            return r.size() > l.size();
        });
        vector<string> results;
        int rlen = 0;
        for (int i = words.size() - 1; i >= 0; i--) {
            string &word = words[i];
            if (0 == rlen || rlen == word.size()) {
                if (1 == word.size()) {
                    rlen = 1;
                    results.push_back(word);
                    continue;
                }
                int si = i - 1;
                for (int cksz = word.size() - 1; cksz >= 1; cksz--) {
                    for (si; si >= 0; si--) {
                        if (words[si].size() != cksz) {
                            continue;
                        }
                        if (0 == word.find(words[si])) {
                            break;
                        }
                    }
                }
                if (si >= 0) {
                    rlen = word.size();
                    results.push_back(word);
                }
            } else {
                break;
            }
        }
        std::sort(results.begin(), results.end());
        if (results.empty()) {
            return "";
        }
        return results[0];
	}
};

#endif

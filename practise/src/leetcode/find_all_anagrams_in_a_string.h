#ifndef _INC_FIND_ALL_ANAGRAMS_IN_A_STRING_
#define _INC_FIND_ALL_ANAGRAMS_IN_A_STRING_

#include <unordered_map>
using std::unordered_map;
#include <vector>
using std::vector;
#include <string>
using std::string;

class FindAllAnagramsInAString {
public:
    static void test() {
        auto ret = vector_ver("cbaebabacd", "abc");
    }

    // Using vector
    static vector<int> vector_ver(string s, string p) {
        vector<int> pts;
        pts.resize(26);
        for (int i = 0; i < p.size(); i++) {
            pts[p[i] - 'a']++;
        }

        vector<int> rets;
        vector<int> sts;
        sts.resize(26);
        bool first = true;
        for (int i = p.size() - 1; i < s.size(); i++) {
            int j = i;
            if (first) {
                j = i - p.size() + 1;
                first = false;
            }
            for (; j <= i; j++) {
                sts[s[j] - 'a']++;
            }
            // Find equal
            if (pts == sts) {rets.push_back(i - p.size() + 1);}
            // Pop the previous one
            sts[s[i - p.size() + 1] - 'a']--;
        }

        return rets;
    }

    // Using unordered_map
    static vector<int> unordered_map_ver(string s, string p) {
        unordered_map<int, int> pts;
        for (int i = 0; i < p.size(); i++) {
            auto fnd = pts.find(p[i]);
            if (fnd == pts.end()) {
                pts.insert(std::make_pair(p[i], 1));
            } else {
                fnd->second++;
            }
        }

        vector<int> rets;
        unordered_map<int, int> sts;
        bool first = true;
        for (int i = p.size() - 1; i < s.size(); i++) {
            int j = i;
            if (first) {
                j = i - p.size() + 1;
                first = false;
            }
            for (; j <= i; j++) {
                auto fnd = sts.find(s[j]);
                if (fnd == sts.end()) {
                    sts.insert(std::make_pair(s[j], 1));
                } else {
                    fnd->second++;
                }
            }
            // Find equal
            bool inc = true;
            for (auto & p : pts) {
                auto fnd = sts.find(p.first);
                if (fnd == sts.end()) {
                    inc = false;
                    break;
                }
                if (fnd->second != p.second) {
                    inc = false;
                    break;
                }
            }
            if (inc) {rets.push_back(i - p.size() + 1);}
            // Pop the previous one
            auto fnd = sts.find(s[i - p.size() + 1]);
            if (fnd->second > 1) {
                fnd->second--;
            } else {
                sts.erase(fnd);
            }
        }

        return rets;
    }
};

#endif

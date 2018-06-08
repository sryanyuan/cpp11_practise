#ifndef _INC_REPEATED_SUBSTRING_PATTERN_
#define _INC_REPEATED_SUBSTRING_PATTERN_

#include <string>
using std::string;

class RepeatedSubstringPattern {
public:
    static void test() {
        auto ret = main("aabaaba");
    }

    static bool main(string s) {
        if (s.size() <= 1) {
            return false;
        }
        string ss = s.substr(0, 1);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != ss[0] || ((s.size() - 1 - i + 1) % ss.size()) != 0) {
                ss.push_back(s[i]);
                continue;
            }
            bool equal = true;
            for (int j = i; j < s.size(); j += ss.size()) {
                string sub = s.substr(j, ss.size());
                if (sub != ss) {
                    equal = false;
                    break;
                }
            }
            if (equal) {
                return true;
            }
            ss.push_back(s[i]);
        }

        return false;
    }
};

#endif

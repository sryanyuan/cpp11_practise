#ifndef _INC_REVERSE_WORDS_IN_A_STRING_III_
#define _INC_REVERSE_WORDS_IN_A_STRING_III_

#include <string>
using std::string;
#include <algorithm>

class ReverseWordsInAStringIII {
public:
    static void test() {
        auto ret = main("Let's take LeetCode contest");
    }

    static string main(string s) {
        int si = 0;
        while (si < s.size()) {
            int ei = si;
            for (ei; ei < s.size(); ei++) {
                if (s[ei] == ' ') {
                    break;
                }
            }
            std::reverse(s.begin() + si, s.begin() + ei);
            si = ei + 1;
        }
        return s;
    }
};

#endif

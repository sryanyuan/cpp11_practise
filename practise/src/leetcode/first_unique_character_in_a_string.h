#ifndef _INC_FIRST_UNIQUE_CHARACTER_IN_A_STRING_
#define _INC_FIRST_UNIQUE_CHARACTER_IN_A_STRING_

#include <string>
using std::string;
#include <algorithm>

class FirstUniqueCharacterInAString {
public:
    static void test() {
        auto ret = main("loveleetcode");
    }

    static int main(string s) {
        if (s.empty()) {
            return -1;
        }
        if (s.size() == 1) {
            return 0;
        }

        std::sort(s.begin(), s.end());
        int pre = s[0];
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != pre) {
                if (cnt == 0) {
                    return i - 1;
                } else {
                    cnt = 0;
                }
                pre = s[i];
            } else {
                cnt++;
            }
        }

        return -1;
    }
};

#endif

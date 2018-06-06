#ifndef _INC_VALID_ANAGRAM_
#define _INC_VALID_ANAGRAM_

#include <string>
using std::string;

class ValidAnagram {
public:
    static bool main(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        if (s.empty()) {
            return true;
        }
        char cnt[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

#endif

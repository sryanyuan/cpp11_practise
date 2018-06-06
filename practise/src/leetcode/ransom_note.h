#ifndef _INC_RANSOM_NOTE_
#define _INC_RANSOM_NOTE_

#include <string>
using std::string;
#include <algorithm>

class RansomNote {
public:
    static bool main(string ransomNote, string magazine) {
        int cnts[26] = {0};
        for (auto c : ransomNote) {
            cnts[c - 'a']++;
        }
        for (auto c : magazine) {
            cnts[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (cnts[i] > 0) {
                return false;
            }
        }
        return true;
    }

    static bool slow(string ransomNote, string magazine) {
        std::sort(ransomNote.begin(), ransomNote.end());
        std::sort(magazine.begin(), magazine.end());

        int i = 0, j = 0;
        for (; i < ransomNote.size() && j < magazine.size();) {
            if (ransomNote[i] != magazine[j]) {
                if (magazine[j] > ransomNote[i]) {
                    return false;
                }
                ++j;
                continue;
            }
            ++i; ++j;
        }
        if (i < ransomNote.size()) {
            return false;
        }
        return true;
    }
};

#endif

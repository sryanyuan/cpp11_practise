#ifndef _INC_JEWELS_AND_STONES_
#define _INC_JEWELS_AND_STONES_

#include "_common_all.h"

class JewelsAndStones {
public:
    static int main(string J, string S) {
        unordered_set<char> jset;
        for (auto c : J) {
            jset.insert(c);
        }
        int cnt = 0;
        for (auto c : S) {
            if (jset.count(c) != 0) {
                ++cnt;
            }
        }
        return cnt;
    }
};

#endif

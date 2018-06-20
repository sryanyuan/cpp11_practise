#ifndef _INC_FIND_SMALLEST_LETTER_GREATER_THAN_TARGET_
#define _INC_FIND_SMALLEST_LETTER_GREATER_THAN_TARGET_

#include "_common_all.h"

class FindSmallestLetterGreaterThanTarget {
public:
    static void test() {
        vector<char> letters;
        letters.push_back('a');
        letters.push_back('b');
        auto ret = main(letters, 'z');
    }

    static char main(vector<char>& letters, char target) {
        char rc = 0;
        int diff = 0;

        for (auto c : letters) {
            int d = 0;
            if (c > target) {
                d = c - target;
            } else {
                d = c + 26 - target;
            }
            if (d < diff || diff == 0) {
                diff = d;
                rc = c;
            }
        }
        return rc;
    }
};

#endif

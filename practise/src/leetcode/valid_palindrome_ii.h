#ifndef _INC_VALID_PALINDROME_II_
#define _INC_VALID_PALINDROME_II_

#include "_common_all.h"

class ValidPalindromeII {
public:
    static void test() {
        auto ret = main("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
    }

    static bool main(string s) {
        return check(s, 0, s.size() - 1, false);
    }

    static bool check(string &s, int l, int r, bool moved) {
        while (l < r) {
            if (s[l] == s[r]) {
                l++; r--;
            } else {
                if (moved) {
                    return false;
                }
                if (s[l + 1] == s[r]) {
                    moved = true;
                    if (check(s, l + 2, r - 1, moved)) {
                        return true;
                    }
                }
                if (s[l] == s[r - 1]) {
                    moved = true;
                    if (check(s, l + 1, r - 2, moved)) {
                        return true;
                    }
                }

                return false;
            }
        }
        return true;
    }
};

#endif

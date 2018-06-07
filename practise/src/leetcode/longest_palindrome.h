#ifndef _INC_LONGEST_PALINDROME_
#define _INC_LONGEST_PALINDROME_

#include <string>
using std::string;

class LongestPalindrome {
public:
    static void test() {
        auto ret = main("ccc");
    }

    static int main(string s) {
        int cnts[26 * 2] = {0};

        for (auto c : s) {
            int index = c - 'A';
            if (c >= 'a') {
                index = 26 + c - 'a';
            }
            cnts[index]++;
        }

        bool odd = false;
        int len = 0;
        for (int i = 0; i < sizeof(cnts) / sizeof(cnts[0]); i++) {
            if (0 == cnts[i]) {
                continue;
            }
            if (cnts[i] % 2 == 0) {
                len += cnts[i];
            } else {
                len += cnts[i] - 1;
                odd = true;
            }
        }

        return odd ? len + 1 : len;
    }
};

#endif

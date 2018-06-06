#ifndef _INC_REVERSE_VOWELS_OF_A_STRING_
#define _INC_REVERSE_VOWELS_OF_A_STRING_

#include <string>
using std::string;

class ReverseVowelsOfAString {
public:
    static void test() {
        string s = "hello";
        s = main(s);
    }

    static string main(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            bool found = false;
            for (l; l < s.size() && l < r; l++) {
                if (isVowels(s[l])) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
            found = false;
            for (r; r >= 0 && r > l; r--) {
                if (isVowels(s[r])) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
            auto tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++; r--;
        }

        return s;
    }

    static bool isVowels(char c) {
        char uc = tolower(c);
        if (uc == 'a' || uc == 'e' || uc == 'i' || uc == 'o' || uc == 'u') {
            return true;
        }
        return false;
    }
};

#endif

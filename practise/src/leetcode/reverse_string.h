#ifndef _INC_REVERSE_STRING_
#define _INC_REVERSE_STRING_

#include <string>
using std::string;

class ReverseString {
public:
    static void test() {
        auto ret = main("hello");
    }

    static string main(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            auto tmp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = tmp;
        }
        return s;
    }
};

#endif

#ifndef _INC_REPEATED_STRING_MATCH_
#define _INC_REPEATED_STRING_MATCH_

#include "_common_all.h"

class RepeatedStringMatch {
public:
    static void test() {
        auto ret = main("abcd", "cdabcdab");
    }

    static int main(string A, string B) {
        if (A.size() >= B.size()) {
            if (string::npos != A.find(B)) {
                return 1;
            }
        }
        string fa = A;
        int rp = 1;
        int maxrp = B.size() / A.size() + 2;
        while (fa.size() < B.size() || rp < maxrp) {
            fa += A;
            rp++;
            auto pos = fa.find(B);
            if (pos != string::npos) {
                return rp;
            }
        }
        return -1;
    }
};

#endif

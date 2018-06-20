#ifndef _INC_ROTATE_STRING_
#define _INC_ROTATE_STRING_

#include "_common_all.h"

class RotateString {
public:
    static void test() {
        auto ret = main("abcde", "cdeab");
    }

    static bool main(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        if (A.size() == B.size() && A.size() == 0) {
            return true;
        }
        int start = A[0];
        string::size_type pos = B.find(start, 0);
        while (pos != string::npos) {
            bool find = true;
            for (int i = 0; i < A.size(); i++) {
                int j = (pos + i) % B.size();
                if (B[j] != A[i]) {
                    find = false;
                }
            }
            if (find) {return true;}
            pos = B.find(start, pos + 1);
        }
        return false;
    }
};

#endif

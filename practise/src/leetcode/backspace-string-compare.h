#ifndef _INC_BACKSPACE_STRING_COMPARE_
#define _INC_BACKSPACE_STRING_COMPARE_

#include "_common_all.h"

class BackspaceStringCompare {
public:
    static bool backspaceCompare(string S, string T) {
        auto s = convert(S);
        auto t = convert(T);
        return s == t;
    }

    static string convert(string &S) {
        stack<char> stk;
        string ret;
        for (auto v : S) {
            if (v == '#') {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else {
                stk.push(v);
            }
        }
        
        ret.resize(stk.size());
        while (!stk.empty()) {
            ret.push_back(stk.top());
            stk.pop();
        }
        return ret;
    }
};

#endif

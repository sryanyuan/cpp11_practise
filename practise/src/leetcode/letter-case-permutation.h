#ifndef _INC_LETTER_CASE_PERMUTATION_
#define _INC_LETTER_CASE_PERMUTATION_

#include "_common_all.h"

class LetterCasePermutation {
public:
    static void test() {
        auto ret = recursion("a1b2");
    }

    static vector<string> recursion(string S) {
        vector<string> rets;
        rp(S, 0, rets);
        return rets;
    }

    static void rp(string &s, int index, vector<string> &rets) {
        if (index >= s.size()) {
            rets.push_back(s);
            return;
        }
        if (s[index] >= '0' && s[index] <= '9') {
            rp(s, index + 1, rets);
        } else {
            rp(s, index + 1, rets);
            string ns = s;
            if (s[index] >= 'a') {
                ns[index] -= 32;
            } else {
                ns[index] += 32;
            }
            rp(ns, index + 1, rets);
        }
    }

    static vector<string> main(string S) {
        int pindex = 0;
        stack<string> stk;
        stk.push(S);

        for (pindex; pindex < S.size(); pindex++) {
            stack<string> nstk;
            while (!stk.empty()) {
                string v = std::move(stk.top());
                stk.pop();
                if (v[pindex] >= '0' && v[pindex] <= '9') {
                    nstk.push(std::move(v));
                } else {
                    nstk.push(v);
                    if (v[pindex] >= 'a') {
                        v[pindex] -= 32;
                    } else {
                        v[pindex] += 32;
                    }
                    nstk.push(std::move(v));
                }
            }
            stk = std::move(nstk);
        }
        vector<string> rets(stk.size());
        int index = 0;
        while (!stk.empty()) {
            rets[index++] = std::move(stk.top());
            stk.pop();
        }
        return rets;
    }
};

#endif

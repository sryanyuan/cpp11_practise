#ifndef _INC_REVERSE_STRING_II_
#define _INC_REVERSE_STRING_II_

#include <string>
using std::string;
#include <algorithm>

class ReverseStringII {
public:
    static string main(string s, int k) {
        if (k <= 1) {
            return s;
        }
        int si = 0;
        while (si < s.size()) {
            int ei = si + k - 1;
            if (ei >= s.size()) {
                ei = s.size() - 1;
            }
            if (ei != si) {
                std::reverse(s.begin() + si, s.begin() + ei + 1);
            }
            si += 2 * k;
        }
        return s;
    }
};

#endif

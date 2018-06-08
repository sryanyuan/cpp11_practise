#ifndef _INC_ASSIGN_COOKIES_
#define _INC_ASSIGN_COOKIES_

#include <vector>
using std::vector;
#include <algorithm>

class AssignCookies {
public:
    static void test() {
        vector<int> g;
        g.push_back(1);
        g.push_back(2);
        vector<int> s;
        s.push_back(1);
        s.push_back(2);
        s.push_back(3);
        auto ret = main(g, s);
    }

    static int main(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int gi = 0, si = 0;

        for (gi; gi < g.size(); ) {
            for (si; si < s.size(); ) {
                if (s[si] < g[gi]) {
                    si++;
                } else {
                    cnt++; gi++; si++;
                    break;
                }
            }
            if (si >= s.size()) {
                break;
            }
        }

        return cnt;
    }
};

#endif

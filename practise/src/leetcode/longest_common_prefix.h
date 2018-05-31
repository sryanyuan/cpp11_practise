#ifndef _INC_LONGEST_COMMON_PREFIX
#define _INC_LONGEST_COMMON_PREFIX

#include <string>
#include <vector>

using std::string;
using std::vector;

class LongestCommonPrefix {
public:
    static string main(vector<string>& strs) {
        int nIndex = 0;
        size_t nStrsCount = strs.size();

        if (0 == nStrsCount) {
            return "";
        }
        if (nStrsCount == 1) {
            return strs[0];
        }

        for (;;) {
            bool done = false;
            for (int i = 1; i < nStrsCount; i++) {
                if (nIndex >= strs[i].size() || nIndex >= strs[i - 1].size()) {
                    done = true;
                    break;
                }
                if (strs[i][nIndex] != strs[i - 1][nIndex]) {
                    done = true;
                    break;
                }
            }
            if (done) {
                break;
            }
            ++nIndex;
        }

        if (nIndex <= 0) {
            return "";
        }
        return strs[0].substr(0, nIndex);
    }
};

#endif

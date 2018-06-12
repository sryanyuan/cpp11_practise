#ifndef _INC_LONGEST_UNCOMMON_SUBSEQUENCE_I_
#define _INC_LONGEST_UNCOMMON_SUBSEQUENCE_I_

#include <string>
using std::string;

class LongestUncommonSubsequenceI {
public:
    static int main(string a, string b) {
        if (a == b) {
            return -1;
        }
        return a.size() > b.size() ? a.size() : b.size();
    }
};

#endif

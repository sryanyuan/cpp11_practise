#ifndef _INC_RELATIVE_RANKS_
#define _INC_RELATIVE_RANKS_

#include <string>
using std::string;
#include <vector>
using std::vector;

class RelativeRanks {
public:
    static vector<string> main(vector<int>& nums) {
        static const char* medals[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        const int MAX = 10001;
        int asc[3] = {-1, -1, -1};

        for (auto v : nums) {
            if (v > asc[2]) {
                asc[0] = asc[1];
                asc[1] = asc[2];
                asc[2] = v;
            } else if (v > asc[1]) {
                asc[0] = asc[1];
                asc[1] = v;
            } else if (v > asc[0]) {
                asc[0] = v;
            }
        }

        vector<string> rets;
        for (auto v : nums) {
            if (v == asc[2]) {
                rets.push_back(medals[0]);
            } else if (v == asc[1]) {
                rets.push_back(medals[1]);
            } else if (v == asc[0]) {
                rets.push_back(medals[2]);
            } else {
                rets.push_back(std::to_string(v));
            }
        }
        return rets;
    }
};

#endif

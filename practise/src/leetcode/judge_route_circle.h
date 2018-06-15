#ifndef _INC_JUDGE_ROUTE_CIRCLE_
#define _INC_JUDGE_ROUTE_CIRCLE_

#include "_common_all.h"

class JudgeRouteCircle {
public:
    static bool main(string moves) {
        if (moves.empty()) {
            return false;
        }
        int cnts[4] = {0};
        for (auto c : moves) {
            cnts[getIndex(c)]++;
        }
        return cnts[0] == cnts[1] && cnts[2] == cnts[3];
    }
    
    static int getIndex(char c) {
        switch (c) {
        case 'U':
            {
                return 0;
            }
        case 'D':
            {
                return 1;
            }
        case 'L':
            {
                return 2;
            }
        case 'R':
            {
                return 3;
            }
        }
        return -1;
    }
};

#endif

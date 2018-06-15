#ifndef _INC_BASEBALL_GAME_
#define _INC_BASEBALL_GAME_

#include "_common_all.h"

class BaseballGame {
public:
    int main(vector<string>& ops) {
        stack<int> scores;
        for (auto &v : ops) {
            if (v == "+") {
                int tp = scores.top();
                scores.pop();
                int tp2 = scores.top();
                scores.push(tp);
                scores.push(tp + tp2);
            } else if (v == "D") {
                scores.push(scores.top() * 2);
            } else if (v == "C") {
                scores.pop();
            } else {
                int score = atoi(v.c_str());
                scores.push(score);
            }
        }
        int sum = 0;
        while (!scores.empty()) {
            sum += scores.top();
            scores.pop();
        }
        return sum;
    }
};

#endif

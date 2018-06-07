#ifndef _INC_FIZZ_BUZZ_
#define _INC_FIZZ_BUZZ_

#include <string>
using std::string;
#include <vector>
using std::vector;

class FizzBuzz {
public:
    static vector<string> main(int n) {
        vector<string> rets;

        int nextFizz = 3;
        int nextBuzz = 5;

        for (int i = 1; i <= n; i++) {
            if (nextFizz == nextBuzz && nextBuzz == i) {
                rets.push_back("FizzBuzz");
                nextFizz += 3;
                nextBuzz += 5;
            } else if (nextBuzz == i) {
                rets.push_back("Buzz");
                nextBuzz += 5;
            } else if (nextFizz == i) {
                rets.push_back("Fizz");
                nextFizz += 3;
            } else {
                rets.push_back(std::to_string(i));
            }
        }

        return rets;
    }
};

#endif

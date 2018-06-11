#ifndef _INC_NEXT_GREATER_ELEMENT_I_
#define _INC_NEXT_GREATER_ELEMENT_I_

#include <vector>
using std::vector;
#include <stack>
using std::stack;
#include <map>
using std::map;

class NextGreaterElementI {
public:
    static vector<int> stk(vector<int>& findNums, vector<int>& nums) {
        stack<int> stk;
        map<int, int> greaterNums;
        vector<int> rets;
        rets.reserve(findNums.size());

        for (auto v : nums) {
            while (!stk.empty() && stk.top() < v) {
                greaterNums.insert(std::make_pair(stk.top(), v));
                stk.pop();
            }
            stk.push(v);
        }

        for (auto v : findNums) {
            auto fnd = greaterNums.find(v);
            if (fnd == greaterNums.end()) {
                rets.push_back(-1);
            } else {
                rets.push_back(fnd->second);
            }
        }
        return rets;
    }

    static vector<int> main(vector<int>& findNums, vector<int>& nums) {
        vector<int> rets;
        rets.reserve(findNums.size());

        for (int i = 0; i < findNums.size(); i++) {
            int ret = -1;
            bool found = false;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == findNums[i]) {
                    found = true;
                    continue;
                }
                if (nums[j] > findNums[i] && found) {
                    ret = nums[j];
                    break;
                }
            }
            rets.push_back(ret);
        }
        return rets;
    }
};

#endif

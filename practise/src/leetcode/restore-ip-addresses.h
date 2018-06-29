#ifndef _INC_RESTORE_IP_ADDRESSES_
#define _INC_RESTORE_IP_ADDRESSES_

#include "_common_all.h"

/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/

class RestoreIpAddresses {
public:
    static void test() {
        auto res = restoreIpAddresses("010010");
    }

    static vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> tmp;
        // Limit 12 characters to avoid time exceeded
        if (s.size() <= 3 * 4) {
            dfs(0, s, tmp, res);
        }
        return res;
    }

    // Time exceeded ...
    /*
    vector<string> res;
    vector<string> tmp;
    dfs(0, s, tmp, res);
    return res;
    */
    static void dfs(int index, string &s, vector<string> &tmp, vector<string> &res) {
        if (index >= s.size() && tmp.size() == 4) {
            string t = tmp[0];
            for (int i = 1; i < tmp.size(); i++) {
                t += ".";
                t += tmp[i];
            }
            res.push_back(std::move(t));
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (index + i < s.size()) {
                string sub = s.substr(index, i + 1);
                int lz = 0;
                for (auto v : sub) {
                    if (v == '0') {
                        lz++;
                    } else {
                        break;
                    }
                }
                if (lz > 0 && sub.size() != 1) {
                    continue;
                }
                int val = atoi(sub.c_str());
                if (val >= 0 && val <= 255) {
                    tmp.push_back(sub);
                    dfs(index + i + 1, s, tmp, res);
                    tmp.pop_back();
                }
            }
        }
    }
};

#endif

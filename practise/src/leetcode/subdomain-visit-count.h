#ifndef _INC_SUBDOMAIN_VISIT_COUNT_
#define _INC_SUBDOMAIN_VISIT_COUNT_

#include "_common_all.h"

class SubdomainVisitCount {
public:
    static void test() {
        vector<string> domains;
        domains.push_back("9001 discuss.leetcode.com");
        auto ret = main(domains);
    }

    static vector<string> main(vector<string>& cpdomains) {
        vector<string> rets;
        unordered_map<string, int> tmmap;
        for (auto &dom : cpdomains) {
            int nupos = dom.find(' ');
            string numstr = dom.substr(0, nupos);
            string dostr = dom.substr(nupos + 1, dom.size() - 1 - nupos + 1 - 1);
            int num = atoi(numstr.c_str());
            auto fnd = tmmap.find(dostr);
            if (fnd == tmmap.end()) {
                tmmap.insert(std::make_pair(dostr, num));
            } else {
                fnd->second += num;
            }
            int dopos = dostr.find('.');
            while (dopos != string::npos) {
                string sub = dostr.substr(dopos + 1, dostr.size() - 1 - dopos - 1 + 1);
                auto fnd = tmmap.find(sub);
                if (fnd == tmmap.end()) {
                    tmmap.insert(std::make_pair(sub, num));
                } else {
                    fnd->second += num;
                }
                dopos = dostr.find('.', dopos + 1);
            }
        }
        for (auto &pa : tmmap) {
            string val = std::to_string(pa.second);
            val += " ";
            val += pa.first;
            rets.push_back(std::move(val));
        }
        return rets;
    }
};

#endif

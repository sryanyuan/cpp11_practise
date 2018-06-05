#ifndef _INC_ISOMORPHIC_STRINGS_
#define _INC_ISOMORPHIC_STRINGS_

#include <string>
using std::string;

class IsomorphicStrings {
public:
    static void test() {
        auto ret = main("foo", "bar");
        ret = main("egg", "add");
        ret = main("paper", "title");
        ret = main("13", "42");
    }

    static bool main(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        if (s.empty()) {
            return true;
        }

        string sf;
        string tf;
        sf.reserve(s.size()); tf.reserve(s.size());

        char smap[256] = {0};
        char tmap[256] = {0};
        int ss = 0;
        int ts = 0;

        for (int i = 0; i < s.size(); i++) {
            char skey = smap[s[i]];
            if (skey == 0) {
                skey = ++ss;
                smap[s[i]] = skey;
            }
            sf.push_back(skey);

            int tkey = tmap[t[i]];
            if (tkey == 0) {
                tkey = ++ts;
                tmap[t[i]] = tkey;
            }
            tf.push_back(tkey);
        }

        return sf == tf;
    }
};

#endif

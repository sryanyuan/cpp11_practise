#ifndef _INC_WORD_PATTERN_
#define _INC_WORD_PATTERN_

#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;

class WordPattern {
public:
    static void test() {
        auto ret = main("effe", "dog cat cat dog");
    }

    static bool main(string pattern, string str) {
        // Convert pattern
        char cps[26] = {0};
        string np;
        char cp = 'a';

        for (auto c : pattern) {
            if (0 == cps[c - 'a']) {
                cps[c - 'a'] = cp;
                cp++;
                np += cps[c - 'a'];
            } else {
                np += cps[c - 'a'];
            }
        }
        pattern = std::move(np);
        
        // Convert str
        string pinn;
        unordered_map<string, char> pn;
        char* buf = new char[str.size() + 1];
        int si = 0;
        cp = 'a';

        for (int i = 0; i <= str.size(); i++) {
            if (i == str.size() || str[i] == ' ') {
                buf[si] = '\0';
                if (0 == si) {
                    continue;
                }
                si = 0;
                string word = buf;

                auto fnd = pn.find(word);
                if (fnd == pn.end()) {
                    pn.insert(std::make_pair(std::move(word), cp));
                    pinn += cp;
                    cp++;
                } else {
                    pinn += fnd->second;
                }
            } else {
                buf[si++] = str[i];
            }
        }

        delete [] buf;
        buf = nullptr;
        return pinn == pattern;
    }
};

#endif

#ifndef _INC_KEYBOARD_ROW_
#define _INC_KEYBOARD_ROW_

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

class KeyboardRow {
public:
    static void test() {
        vector<string> rets;
        rets.push_back("Hello");
        rets.push_back("Alaska");
        rets.push_back("Dad");
        rets.push_back("Peace");
        auto ret = main(rets);
    }

    static vector<string> main(vector<string>& words) {
        vector<string> rets;
        int keytable[26] = {1, 2, 2, 1, 0, 1, 1,
            1, 0, 1, 1, 1, 2, 2,
            0, 0, 0, 0, 1, 0,
            0, 2, 0, 2, 0, 2};
        /*unordered_map<int, int> krow;
        // row 0
        krow.insert(std::make_pair('q', 0));
        krow.insert(std::make_pair('w', 0));
        krow.insert(std::make_pair('e', 0));
        krow.insert(std::make_pair('r', 0));
        krow.insert(std::make_pair('t', 0));
        krow.insert(std::make_pair('y', 0));
        krow.insert(std::make_pair('u', 0));
        krow.insert(std::make_pair('i', 0));
        krow.insert(std::make_pair('o', 0));
        krow.insert(std::make_pair('p', 0));
        // row 1
        krow.insert(std::make_pair('a', 1));
        krow.insert(std::make_pair('s', 1));
        krow.insert(std::make_pair('d', 1));
        krow.insert(std::make_pair('f', 1));
        krow.insert(std::make_pair('g', 1));
        krow.insert(std::make_pair('h', 1));
        krow.insert(std::make_pair('j', 1));
        krow.insert(std::make_pair('k', 1));
        krow.insert(std::make_pair('l', 1));
        // row 2
        krow.insert(std::make_pair('z', 2));
        krow.insert(std::make_pair('x', 2));
        krow.insert(std::make_pair('c', 2));
        krow.insert(std::make_pair('v', 2));
        krow.insert(std::make_pair('b', 2));
        krow.insert(std::make_pair('n', 2));
        krow.insert(std::make_pair('m', 2));*/
        
        for (auto &s : words) {
            int kr = -1;
            bool same = true;
            for (auto c : s) {
                int index = keytable[tolower(c) - 'a'];
                if (kr == -1) {
                    kr = index;
                } else if (kr != index) {
                    same = false;
                    break;
                }
            }
            if (same) {
                rets.push_back(s);
            }
        }
        return rets;
    }
};

#endif

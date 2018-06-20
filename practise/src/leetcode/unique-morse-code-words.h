#ifndef _INC_UNIQUE_MORSE_CODE_WORDS_
#define _INC_UNIQUE_MORSE_CODE_WORDS_

#include "_common_all.h"

class UniqueMorseCodeWords {
public:
    static int main(vector<string>& words) {
        static const char* morseMap[] = {
            ".-","-...","-.-.","-..",
            ".","..-.","--.","....",
            "..",".---","-.-",".-..",
            "--","-.","---",".--.",
            "--.-",".-.","...","-",
            "..-","...-",".--","-..-",
            "-.--","--.."};
        unordered_set<string> sset;
        for (auto &str : words) {
            string key;
            for (auto c : str) {
                key += morseMap[c - 'a'];
            }
            sset.insert(std::move(key));
        }
        return sset.size();
    }
};

#endif

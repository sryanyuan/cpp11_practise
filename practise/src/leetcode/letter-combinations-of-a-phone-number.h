#ifndef _INC_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_
#define _INC_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_

#include "_common_all.h"

class LetterCombinationsOfAPhoneNumber {
public:
    static void test() {
        auto ret = letterCombinations("23");
    }

    static vector<string> letterCombinations(string digits) {
        vector<string> res;
        string p;
        recursion(digits, p, 0, res);
        return res;
    }

    static void recursion(string &digits, string &parent, int index, vector<string> &res) {
        static string numChars[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if (index >= digits.size()) {
            if (!parent.empty()) {
                res.push_back(parent);
            }
            return;
        }
        string &numChar = numChars[digits[index] - '2'];
        for (auto c : numChar) {
            string s = parent + c;
            recursion(digits, s, index + 1, res);
        }
    }
};

#endif

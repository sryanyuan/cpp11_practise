#ifndef _INC_REVERSE_WORDS_IN_A_STRING_
#define _INC_REVERSE_WORDS_IN_A_STRING_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given an input string, reverse the string word by word.

Example:  


Input: "the sky is blue",
Output: "blue is sky the".


Note:


	A word is defined as a sequence of non-space characters.
	Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
	You need to reduce multiple spaces between two words to a single space in the reversed string.


Follow up: For C programmers, try to solve it in-place in O(1) space.
*/

class ReverseWordsInAString {
public:
	static void test() {
        string s = "  the    sky  is  blue  ";
		reverseWords(s);
        printf("%s", s.c_str());
	}

	static void reverseWords(string &s) {
        vector<string> words;
		char *buf = new char[s.size() + 1];
        buf[0] = 0;
        int si = 0;

        for (auto c : s) {
            if (c == ' ') {
                if (si != 0) {
                    buf[si] = 0;
                    string ns = buf;
                    words.push_back(std::move(ns));
                    si = 0;
                }
            } else {
                buf[si++] = c;
            }
        }
        if (si != 0) {
            buf[si] = 0;
            string ns = buf;
            words.push_back(std::move(ns));
        }

        int offset = 0;
        for (int i = words.size() - 1; i >= 0; i--) {
            memcpy(buf + offset, words[i].c_str(), words[i].size());
            offset += words[i].size();
            if (i != 0) {
                buf[offset++] = ' ';
            } else {
                buf[offset++] = 0;
            }
        }

        string res = buf;
        delete[] buf;
        buf = nullptr;
        s = res;
	}
};

#endif
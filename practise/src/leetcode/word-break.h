#ifndef _INC_WORD_BREAK_
#define _INC_WORD_BREAK_

/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

#include "_common_all.h"

class WorkBreak {
    static bool wordBreak(string s, vector<string>& wordDict) {
        // Dynamic programming
        if (wordDict.empty()) {
            return false;
        }
        unordered_set<string> wset(wordDict.begin(), wordDict.end());
        vector<bool> appear(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= i; j++) {
                bool preBreak = false;
                if (j == 0) {
                    preBreak = true;
                } else {
                    preBreak = appear[j - 1];
                }
                if (preBreak && wset.count(s.substr(j, i - j + 1)) != 0) {
                    appear[i] = true;
                    break;
                }
            }
        }
        return appear.back();
    }

    /*
    Time exceeded (Deep first search)
    unordered_set<string> wset(wordDict.begin(), wordDict.end());
    bool res = false;
    for (int i = 1; i <= s.size(); i++) {
    dfs(s, 0, i, wset, res);
    }
    return res;
    */
    static void dfs(string &s, int si, int len, unordered_set<string> &wset, bool &res) {
        if (res) {
            return;
        }
        if (wset.count(s.substr(si, len)) == 0) {
            return;
        }
        if (si + len - 1 >= s.size() - 1) {
            res = true;
            return;
        }
        for (int i = si + len; i < s.size(); i++) {
            dfs(s, si + len, i - (si + len) + 1, wset, res);
        }
    }
};

#endif

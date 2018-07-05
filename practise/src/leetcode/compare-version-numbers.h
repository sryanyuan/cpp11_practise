#ifndef _INC_COMPARE_VERSION_NUMBERS_
#define _INC_COMPARE_VERSION_NUMBERS_

/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
*/

#include "_common_all.h"

class CompareVersionNumbers {
public:
    static void test() {
        auto res = compareVersion("0.1", "1.1");
    }

    static int compareVersion(string version1, string version2) {
        char *buf = new char[version1.size() > version2.size() ? version1.size() + 1 : version2.size() + 1];
        *buf = 0;
        int si = 0;
        vector<int> v1s;
        vector<int> v2s;
        for (int i = 0; i < version1.size(); i++) {
            if (version1[i] != '.') {
                buf[si++] = version1[i];
            }
            if (version1[i] == '.' || i == version1.size() - 1) {
                if (si != 0) {
                    buf[si] = 0;
                    v1s.push_back(atoi(buf));
                    si = 0;
                }
            }
        }
        for (int i = 0; i < version2.size(); i++) {
            if (version2[i] != '.') {
                buf[si++] = version2[i];
            }
            if (version2[i] == '.' || i == version2.size() - 1) {
                if (si != 0) {
                    buf[si] = 0;
                    v2s.push_back(atoi(buf));
                    si = 0;
                }
            }
        }

        for (int i = 0; i < (v1s.size() > v2s.size() ? v1s.size() : v2s.size()); i++) {
            int v1 = 0, v2 = 0;
            if (i < v1s.size()) {
                v1 = v1s[i];
            }
            if (i < v2s.size()) {
                v2 = v2s[i];
            }
            if (v1 > v2) {
                return 1;
            } else if (v1 < v2) {
                return -1;
            }
        }

        delete[] buf;
        return 0;
    }
};

#endif

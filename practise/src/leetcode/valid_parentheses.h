#ifndef _INC_VALID_PARENTHESES_
#define _INC_VALID_PARENTHESES_

#include <string>
using std::string;

#include <stack>
using std::stack;

class ValidParentheses {
public:
    static bool main(string s) {
        // Using stack
        stack<char> stk;

        if (s.empty()) {
            return true;
        }
        if (s.size() % 2 != 0) {
            return false;
        }

        for (size_t i = 0; i < s.size(); i++) {
            char ch = s[i];

            // Left bracket
            if (ch == '(' ||
                ch == '{' ||
                ch == '[') {
                    stk.push(ch);
            } else if (ch == ')' ||
                ch == '}' ||
                ch == ']') {
                    if (stk.empty()) {
                        return false;
                    }
                    char chp = stk.top();
                    stk.pop();

                    if (ch == ')' && chp != '(') {
                        return false;
                    } else if (ch == '}' && chp != '{') {
                        return false;
                    } else if (ch == ']' && chp != '[') {
                        return false;
                    }
            } else {
                // Invalid input
                return false;
            }
        }

        // Stack must be empty
        if (!stk.empty()) {
            return false;
        }

        return true;
    }
};

#endif

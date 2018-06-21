#ifndef _INC_GENERATE_PARENTHESES_
#define _INC_GENERATE_PARENTHESES_

#include "_common_all.h"

class GenerateParentheses {
public:
	static void test() {
		auto ret = generateParenthesis(3);
	}

	static vector<string> generateParenthesis(int n) {
		if (n <= 0) {
			return vector<string>();
		}
		vector<string> res;
		string p = "(";
		build(n, p, res);
		return res;
	}

	static void build(int n, string &p, vector<string> &res) {
		if (p.size() >= 2 * n) {
			res.push_back(p);
			return;
		}
		int lc = 0, rc = 0;
		for (auto c : p) {
			if (c == '(') {
				++lc;
			}
			else if (c == ')') {
				++rc;
			}
		}
		if (lc < n) {
			string np = p + '(';
			build(n, np, res);
		}
		if (rc < lc) {
			string np = p + ')';
			build(n, np, res);
		}
	}
};

#endif

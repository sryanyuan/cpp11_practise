#ifndef _INC_COMMON_LIST_
#define _INC_COMMON_LIST_

#include "_common_all.h"
#include <sstream>

class SingleLinkedListCls {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

	static void trimLeftTrailingSpaces(string &input) {
		input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
			return !isspace(ch);
		}));
	}

	static void trimRightTrailingSpaces(string &input) {
		input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
			return !isspace(ch);
		}).base(), input.end());
	}

	static vector<int> stringToIntegerVector(string input) {
		vector<int> output;
		trimLeftTrailingSpaces(input);
		trimRightTrailingSpaces(input);
		input = input.substr(1, input.length() - 2);
		std::stringstream ss;
		ss.str(input);
		string item;
		char delim = ',';
		while (getline(ss, item, delim)) {
			output.push_back(stoi(item));
		}
		return output;
	}

	static ListNode* stringToListNode(string input) {
		// Generate list from the input
		vector<int> list = stringToIntegerVector(input);

		// Now convert that list into linked list
		ListNode* dummyRoot = new ListNode(0);
		ListNode* ptr = dummyRoot;
		for (int item : list) {
			ptr->next = new ListNode(item);
			ptr = ptr->next;
		}
		ptr = dummyRoot->next;
		delete dummyRoot;
		return ptr;
	}

	static string listNodeToString(ListNode* node) {
		if (node == nullptr) {
			return "[]";
		}

		string result;
		while (node) {
			result += std::to_string(node->val) + ", ";
			node = node->next;
		}
		return "[" + result.substr(0, result.length() - 2) + "]";
	}
};

#endif

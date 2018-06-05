#ifndef _INC_PALINDROME_LINKED_LIST_
#define _INC_PALINDROME_LINKED_LIST_

#include <stack>
using std::stack;

class PalindromeLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    static void test() {
        ListNode node(1);
        node.next = new ListNode(0);
		node.next->next = new ListNode(1);
        auto ret = main(&node);
    }

    static bool main(ListNode* head) {
        if (nullptr == head || head->next == nullptr) {
            return true;
        }
		ListNode* fast = head;
		ListNode* slow = head;

		// Finding the middle node and push the value of left part
		stack<int> leftVals;
		leftVals.push(head->val);
		while (fast->next != nullptr && fast->next->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
			leftVals.push(slow->val);
		}

		if (nullptr != fast->next) {
			slow = slow->next;
		}
		while (slow != nullptr && !leftVals.empty()) {
			int val = leftVals.top();
			leftVals.pop();
			if (val != slow->val) {
				return false;
			}
			slow = slow->next;
		}

		if (slow != nullptr || !leftVals.empty()) {
			return false;
		}

        return true;
    }
};

#endif

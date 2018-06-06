#ifndef _INC_LINKED_LIST_CIRCLE_
#define _INC_LINKED_LIST_CIRCLE_

class LinkedListCircle {
private:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

public:
	static bool main(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;

		while (nullptr != slow && nullptr != fast) {
			// Slow move 1 step
			slow = move(slow, 1);
			// Fast move 2 step
			fast = move(fast, 2);

			if (nullptr != fast && fast == slow) {
				return true;
			}
		}

		return false;
	}

	static ListNode* move(ListNode* node, int step) {
		int i = 0;
		while (i < step && node != nullptr) {
			node = node->next;
			i++;
		}
		return node;
	}
};

#endif

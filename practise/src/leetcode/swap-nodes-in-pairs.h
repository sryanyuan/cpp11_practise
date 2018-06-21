#ifndef _INC_SWAP_NODES_IN_PAIRS_
#define _INC_SWAP_NODES_IN_PAIRS_

#include "_common_list.h"

class SwapNodesInPairs : public SingleLinkedListCls {
public:
	static void test() {
		auto head = stringToListNode("[1,2,3,4]");
		auto ret = swapPairs(head);
	}

	static ListNode* swapPairs(ListNode* head) {
		if (nullptr == head) {
			return nullptr;
		}
		ListNode *oh = head;
		ListNode *pre = head;
		ListNode *cur = head->next;
		ListNode *lp = nullptr;
		while (pre != nullptr && cur != nullptr) {
			if (nullptr != lp) {
				lp->next = cur;
			}
			lp = pre;
			ListNode *next = cur->next;
			cur->next = pre;
			pre->next = next;
			if (oh == pre && oh == head) {
				oh = cur;
			}
			if (next == nullptr || next->next == nullptr) {
				break;
			}
			pre = next;
			cur = next->next;
		}
		return oh;
	}
};

#endif

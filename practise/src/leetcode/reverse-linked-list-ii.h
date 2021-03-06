#ifndef _INC_REVERSE_LINKED_LIST_II_
#define _INC_REVERSE_LINKED_LIST_II_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:


Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

*/

class ReverseLinkedListIi : public SingleLinkedListCls {
public:
	static void test() {
		auto res = reverseBetween(stringToListNode("[3,5]"), 1, 2);
	}

	static ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) {
            return head;
        }
        ListNode *mpnode = nullptr;
		ListNode *mnode = nullptr;
        ListNode *mtail = nullptr;
        ListNode *nnode = nullptr;
        ListNode *node = head;
        int index = 1;
        while (nullptr != node) {
            if (index == m) {
                mnode = node;
                mtail = node;
                node = node->next;
            } else if (index == n) {
                nnode = node;
                ListNode *next = node->next;
                node->next = mtail;
                if (mnode == head) {
                    head = nnode;
                    mnode->next = next;
                } else {
                    mpnode->next = node;
                    mnode->next = next;
                }
                break;
            } else if (nullptr != mtail) {
                ListNode *next = node->next;
                node->next = mtail;
                mtail = node;
                node = next;
            } else if (nullptr == mnode) {
                mpnode = node;
                node = node->next;
            } else {
                node = node->next;
            }
            ++index;
        }
        return head;
	}
};

#endif

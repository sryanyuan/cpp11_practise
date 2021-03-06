#ifndef _INC_PARTITION_LIST_
#define _INC_PARTITION_LIST_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:


Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

*/

class PartitionList : public SingleLinkedListCls {
public:
	static void test() {
		auto res = partition(stringToListNode("[3,1,2]"), 3);
	}

	static ListNode* partition(ListNode* head, int x) {
        if (nullptr == head || nullptr == head->next) {return head;}
        ListNode *prev = head;
		ListNode *node = head->next;
        ListNode *pend = nullptr;
        bool p = false;
        if (prev->val < x) {
            pend = prev;
        } else {
            p = true;
        }
        while (nullptr != node) {
            if (node->val < x) {
                if (!p) {
                    pend = node;
                } else {
                    if (nullptr == pend) {
                        prev->next = node->next;
                        node->next = head;
                        head = node;
                    } else {
                        prev->next = node->next;
                        ListNode *tmp = pend->next;
                        pend->next = node;
                        node->next = tmp;
                    }
                    pend = node;
                    node = prev->next;
                    continue;
                }
            } else {
                p = true;
            }
            prev = node;
            node = node->next;
        }
        return head;
	}
};

#endif

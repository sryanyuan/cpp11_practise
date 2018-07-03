#ifndef _INC_REORDER_LIST_
#define _INC_REORDER_LIST_

/*
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

#include "_common_list.h"

class ReorderList : public SingleLinkedListCls {
public:
    static void test() {
        auto ls = stringToListNode("[1,2,3,4,5]");
        reorderList(ls);
    }

    static void reorderList(ListNode* head) {
        if (nullptr == head) {
            return;
        }
        stack<ListNode*> prevs;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next) {
            prevs.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast == slow) {
            return;
        }
        if (fast->next != nullptr) {
            prevs.push(slow);
        }
        slow = slow->next;
        bool first = true;
        while (!prevs.empty()) {
            ListNode *cur = prevs.top();
            prevs.pop();
            ListNode *next = slow->next;
            ListNode *pnext = cur->next;
            cur->next = slow;
            if (first) {
                slow->next = nullptr;
            } else {
                slow->next = pnext;
            }
            slow = next;
        }
    }
};

#endif

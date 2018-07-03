#ifndef _INC_LINKED_LIST_CYCLE_II_
#define _INC_LINKED_LIST_CYCLE_II_

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

#include "_common_all.h"
#include "_common_list.h"

class LinkedListCircleII : public SingleLinkedListCls {
public:
    static ListNode *detectCycle(ListNode *head) {
        if (nullptr == head) {
            return nullptr;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                // Must with a circle
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

#endif

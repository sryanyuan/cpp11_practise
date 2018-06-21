#ifndef _INC_REMOVE_NTH_NODE_FROM_END_OF_LIST_
#define _INC_REMOVE_NTH_NODE_FROM_END_OF_LIST_

#include "_common_list.h"

class RemoveNthNodeFromEndOfList : public SingleLinkedListCls {
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        int len = 0;
        ListNode *node = head;
        while (nullptr != node) {
            ++len;
            node = node->next;
        }
        int hn = len - n;

        int cnt = 1;
        node = head;
        if (hn == 0) {
            return head->next;
        }
        ListNode *pre = head;
        ListNode *cur = head->next;
        for (int i = 1; i <= hn; i++) {
            if (i == hn) {
                pre->next = cur->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

#endif

#ifndef _INC_DELETE_NODE_IN_A_LINKED_LIST_
#define _INC_DELETE_NODE_IN_A_LINKED_LIST_

class DeleteNodeInALinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    static void main(ListNode* node) {
        *node = *node->next;
    }

    static void bad1(ListNode* node) {
        ListNode *cur = node;
        cur->val = cur->next->val;
        cur->next = cur->next->next;
    }

    static void bad(ListNode* node) {
        ListNode *cur = node;
        while (nullptr != cur->next) {
            ListNode* next = cur->next;
            cur->val = next->val;
            if (nullptr == next->next) {
                cur->next = nullptr;
                break;
            }
            cur = next;
        }
    }
};

#endif

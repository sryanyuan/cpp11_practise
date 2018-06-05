#ifndef _INC_REMOVE_LINKED_LIST_ELEMENTS_
#define _INC_REMOVE_LINKED_LIST_ELEMENTS_

class RemoveLinkedListElements {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    static ListNode* main(ListNode* head, int val) {
        if (nullptr == head) {
            return nullptr;
        }

        ListNode *node = head;
        ListNode *prev = head;
        while (nullptr != node) {
            if (node->val == val) {
                if (node == head) {
                    head = node->next;
                    node = head;
                    prev = head;
                } else {
                    prev->next = node->next;
                    node = node->next;
                }
            } else {
                prev = node;
                node = node->next;
            }
        }

        return head;
    }
};

#endif

#ifndef _INC_REMOVE_DUPLICATES_FROM_SORTED_LIST_
#define _INC_REMOVE_DUPLICATES_FROM_SORTED_LIST_

class RemoveDuplicatesFromSortedList {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    static ListNode* main(ListNode* head) {
        if (nullptr == head) {
            return nullptr;
        }
        ListNode* node = head;
        ListNode* prev = nullptr;

        while (nullptr != node) {
            if (nullptr != prev) {
                if (prev->val == node->val) {
                    // This node need to be deleted
                    ListNode* pn = node;
                    node = node->next;
                    prev->next = nullptr;
                    delete pn;
                } else {
                    prev->next = node;
                    prev = node;
                    node = node->next;
                }
            } else {
                prev = node;
                node = node->next;
            }
        }

        prev->next = nullptr;
        return head;
    }
};

#endif

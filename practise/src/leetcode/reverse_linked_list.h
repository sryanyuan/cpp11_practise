#ifndef _INC_REVERSE_LINKED_LIST_
#define _INC_REVERSE_LINKED_LIST_

class ReverseLinkedList {
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
        ListNode* pren = head;
        ListNode* node = head->next;
        head->next = nullptr;

        while (nullptr != node) {
            ListNode* next = node->next;
            node->next = pren;
            pren = node;
            node = next;
        }

        return pren;
    }
};

#endif

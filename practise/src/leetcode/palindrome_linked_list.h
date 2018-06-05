#ifndef _INC_PALINDROME_LINKED_LIST_
#define _INC_PALINDROME_LINKED_LIST_

class PalindromeLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    static void test() {
        ListNode node(-1);
        node.next = new ListNode(1);
        auto ret = main(&node);
    }

    static bool main(ListNode* head) {
        if (nullptr == head) {
            return true;
        }
        ListNode* tail = head;
        while (nullptr != tail->next) {
            tail = tail->next;
        }

        for (; head <= tail; head++, tail--) {
            if (head->val != tail->val) {
                return false;
            }
        }

        return true;
    }
};

#endif

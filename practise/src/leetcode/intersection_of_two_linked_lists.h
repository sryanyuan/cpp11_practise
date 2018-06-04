#ifndef _INC_INTERSECTION_OF_TWO_LINKED_LISTS_
#define _INC_INTERSECTION_OF_TWO_LINKED_LISTS_

/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:
A:          a1 ¡ú a2
                   ¨K
                     c1 ¡ú c2 ¡ú c3
                   ¨J              
B:     b1 ¡ú b2 ¡ú b3

begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

class IntersectionOfTwoLinkedLists {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    static ListNode* main(ListNode* headA, ListNode* headB) {
        if (nullptr == headA || nullptr == headB) {
            return nullptr;
        }

        ListNode* pa = headA;
        ListNode* pb = headB;
        int ar = 0;
        int br = 0;

        for (;;) {
            if (pa == pb) {
                return pa;
            }

            pa = pa->next;
            if (nullptr == pa) {
                if (ar != 0) {
                    return nullptr;
                } else {
                    pa = headB;
                    ++ar;
                }
            }

            pb = pb->next;
            if (nullptr == pb) {
                if (br != 0) {
                    return nullptr;
                } else {
                    pb = headA;
                    ++br;
                }
            }
        }
    }
};

#endif

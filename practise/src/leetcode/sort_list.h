#ifndef _INC_SORT_LIST
#define _INC_SORT_LIST

/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

#include "_common_list.h"

class SortList : public SingleLinkedListCls {
public:
    static void test() {
        auto node = stringToListNode("[4,2,1,3,10,5,6,9,7,8,-1]");
        node = sortList(node);
        auto res = listNodeToString(node);
    }

    static ListNode* sortList(ListNode* head) {
        if (nullptr == head) {
            return head;
        }

        ListNode* newHead = head;
        ListNode* curNode = head->next;
        ListNode* prevNode = head;

        while (curNode != nullptr) {
            if (curNode->val < prevNode->val) {
                // Search for the correct position
                ListNode* searchNode = newHead;
                ListNode* searchPrev = nullptr;

                while (searchNode != nullptr) {
                    if (curNode->val >= searchNode->val) {
                        searchPrev = searchNode;
                        searchNode = searchPrev->next;
                        continue;
                    }
                    // Do exchange
                    prevNode->next = curNode->next;
                    if (searchPrev == nullptr) {
                        // New head should update
                        curNode->next = newHead;
                        newHead = curNode;
                    } else {
                        curNode->next = searchNode;
                        searchPrev->next = curNode;
                    }
                    curNode = prevNode->next;
                    break;
                }
            } else {
                prevNode = curNode;
                curNode = curNode->next;
            }
        }

        return newHead;
    }
};

#endif

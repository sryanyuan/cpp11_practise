#ifndef _INC_COMMON_LIST_
#define _INC_COMMON_LIST_

#include "_common_all.h"

class SingleLinkedListCls {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
};

#endif

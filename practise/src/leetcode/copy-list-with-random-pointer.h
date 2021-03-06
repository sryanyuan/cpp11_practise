#ifndef _INC_COPY_LIST_WITH_RANDOM_POINTER_
#define _INC_COPY_LIST_WITH_RANDOM_POINTER_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.



Return a deep copy of the list.
*/

class CopyListWithRandomPointer {
private:
    struct RandomListNode {
        int label;
        RandomListNode *next, *random;
        RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
    };

public:
	static void test() {
        auto ptr = new RandomListNode(1);
        RandomListNode *tail = ptr;
        tail->next = new RandomListNode(2);
        tail = tail->next;
        tail->next = new RandomListNode(2);
        tail = tail->next;
        tail->next = new RandomListNode(2);
        tail = tail->next;
		auto res = copyRandomList(ptr);
	}

	static RandomListNode *copyRandomList(RandomListNode *head) {
		if (nullptr == head) {
            return head;
        }
        unordered_map<RandomListNode*, RandomListNode*> ptrmap;
        RandomListNode *cpnode = nullptr;
        RandomListNode *cptnode = cpnode;
        RandomListNode *srcnode = head;
        while (nullptr != srcnode) {
            if (nullptr == cptnode) {
                cpnode = new RandomListNode(srcnode->label);
                cptnode = cpnode;
            } else {
                cptnode->next = new RandomListNode(srcnode->label);
                cptnode = cptnode->next;
            }
            ptrmap[srcnode] = cptnode;
            cptnode->random = srcnode->random;
            srcnode = srcnode->next;
        }

        cptnode = cpnode;
        while (nullptr != cptnode) {
            if (nullptr != cptnode->random) {
                cptnode->random = ptrmap[cptnode->random];
            }
            cptnode = cptnode->next;
        }
        return cpnode;
	}
};

#endif

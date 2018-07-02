#ifndef _INC_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_
#define _INC_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given a binary tree


struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}


Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:


	You may only use constant extra space.
	Recursive approach is fine, implicit stack space does not count as extra space for this problem.


Example:

Given the following binary tree,


     1
   /  \
  2    3
 / \    \
4   5    7


After calling your function, the tree should look like:


     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL

*/

class PopulatingNextRightPointersInEachNodeIi : public TreeNodeCls {
private:
    struct TreeLinkNode {
        int val;
        TreeLinkNode *left;
        TreeLinkNode *right;
        TreeLinkNode *next;

        TreeLinkNode(int v) {
            left = right = next = nullptr;
            val = v;
        }
    };

public:
	static void test() {
		auto t = stringToTreeNodeT<TreeLinkNode>("[2,1,3,0,7,9,1,2,null,1,0,null,null,8,8,null,null,null,null,7]");
        connect(t);
	}

	static void connect(TreeLinkNode *root) {
		if (nullptr == root) {
            return;
        }

        if (nullptr != root->left) {
            if (nullptr != root->right) {
                root->left->next = root->right;
            } else {
                TreeLinkNode *node = root;
                while (node->next != nullptr) {
                    node = node->next;
                    if (nullptr != node->left) {
                        root->left->next = node->left;
                    } else {
                        root->left->next = node->right;
                    }
                    if (nullptr != root->left->next) {
                        break;
                    }
                }
            }
        }
        if (nullptr != root->right) {
            TreeLinkNode *node = root;
            while (node->next != nullptr) {
                node = node->next;
                if (nullptr != node->left) {
                    root->right->next = node->left;
                } else {
                    root->right->next = node->right;
                }
                if (nullptr != root->right->next) {
                    break;
                }
            }
        }
        connect(root->right);
        connect(root->left);
	}
};

#endif

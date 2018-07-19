#ifndef _INC_KTH_SMALLEST_ELEMENT_IN_A_BST_
#define _INC_KTH_SMALLEST_ELEMENT_IN_A_BST_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:


Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3


Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

class KthSmallestElementInABst : public TreeNodeCls {
public:
	static void test() {
		
	}

	static int kthSmallest(TreeNode* root, int k) {
		int ki = k - 1;
        int index = 0;
        int res = 0;
        walk(root, ki, index, res);
        return res;
	}

    static void walk(TreeNode *node, int ki, int &index, int &res) {
        if (nullptr == node) {
            return;
        }
        if (index > ki) {
            return;
        }
        walk(node->left, ki, index, res);
        // Visit
        ++index;
        if (index - 1 == ki) {
            res = node->val;
            return;
        }
        walk(node->right, ki, index, res);
    }
};

#endif
#ifndef _INC_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_
#define _INC_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4


Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of of nodes 5 and 1 is 3.


Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
             according to the LCA definition.

Note:


	All of the nodes' values will be unique.
	p and q are different and both values will exist in the binary tree.

*/

class LowestCommonAncestorOfABinaryTree : public TreeNodeCls {
public:
	static void test() {
		
	}

	static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> tmp;
		vector<TreeNode*> pvs;
        path(root, p, tmp, pvs);
        vector<TreeNode*> qvs;
        path(root, q, tmp, qvs);
        int ci = 0;
        for (int i = 0; i < pvs.size() && i < qvs.size(); i++) {
            if (pvs[i]->val == qvs[i]->val) {
                ci = i;
            } else {
                break;
            }
        }
        return pvs[ci];
	}

    static void path(TreeNode *node, TreeNode *dst, vector<TreeNode*> &tmp, vector<TreeNode*> &res) {
        if (nullptr == node) {
            return;
        }
        if (node->val == dst->val) {
            tmp.push_back(node);
            res = tmp;
            tmp.pop_back();
            return;
        }
        tmp.push_back(node);
        path(node->left, dst, tmp, res);
        path(node->right, dst, tmp, res);
        tmp.pop_back();
    }
};

#endif

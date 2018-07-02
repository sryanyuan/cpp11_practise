#ifndef _INC_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_
#define _INC_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).


For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7



return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

*/

class BinaryTreeLevelOrderTraversal : public TreeNodeCls {
public:
	static void test() {
		
	}

	static vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
		if (nullptr == root) {
            return res;
        }
        vector<TreeNode*> nodes(1, root);
        while (!nodes.empty()) {
            vector<TreeNode*> cnodes;
            vector<int> vals;
            for (auto v : nodes) {
                vals.push_back(v->val);
                if (nullptr != v->left) {
                    cnodes.push_back(v->left);
                }
                if (nullptr != v->right) {
                    cnodes.push_back(v->right);
                }
            }
            nodes = std::move(cnodes);
            res.push_back(std::move(vals));
        }
        return res;
	}
};

#endif
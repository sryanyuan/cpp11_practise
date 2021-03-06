#ifndef _INC_BINARY_TREE_RIGHT_SIDE_VIEW_
#define _INC_BINARY_TREE_RIGHT_SIDE_VIEW_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:


Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

*/

class BinaryTreeRightSideView : public TreeNodeCls {
public:
	static void test() {
		auto t = stringToTreeNode("[1,2,3,null,5,null,4]");
        auto res = rightSideView(t);
	}

	static vector<int> rightSideView(TreeNode* root) {
		vector<vector<int>> rtobs;
        vector<int> tmp;
        walk(root, tmp, rtobs);
        vector<int> res;
        if (rtobs.empty()) {
            return res;
        }
        res = std::move(rtobs[0]);
        for (int i = 1; i < rtobs.size(); i++) {
            for (int j = res.size(); j < rtobs[i].size(); j++) {
                res.push_back(rtobs[i][j]);
            }
        }
        return res;
	}

    static void walk(TreeNode *node, vector<int> &tmp, vector<vector<int>> &rtobs) {
        if (node == nullptr) {
            return;
        }
        if (nullptr == node->left && nullptr == node->right) {
            tmp.push_back(node->val);
            rtobs.push_back(tmp);
            tmp.pop_back();
            return;
        }
        tmp.push_back(node->val);
        walk(node->right, tmp, rtobs);
        walk(node->left, tmp, rtobs);
        tmp.pop_back();
    } 
};

#endif

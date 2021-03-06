#ifndef _INC_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_
#define _INC_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given


preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

Return the following binary tree:


    3
   / \
  9  20
    /  \
   15   7
*/

class ConstructBinaryTreeFromPreorderAndInorderTraversal : public TreeNodeCls {
public:
	static void test() {
        int prevals[] = {3, 9, 20, 15, 7};
		vector<int> preorder(prevals, prevals + sizeof(prevals) / sizeof(prevals[0]));
        int invals[] = {9, 3, 15, 20, 7};
        vector<int> inorder(invals, invals + sizeof(invals) / sizeof(invals[0]));
        auto ret = buildTree(preorder, inorder);
	}

	static TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || preorder.size() != inorder.size()) {
            return nullptr;
        }
        // Generate quick search map
        unordered_map<int, int> imp;
        for (int i = 0; i < inorder.size(); i++) {
            imp[inorder[i]] = i;
        }
		return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, nullptr, false, imp);
	}

    static TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, TreeNode *parent, bool left, unordered_map<int, int> &imp) {
        if (ps > pe) {return nullptr;}
        TreeNode *apnode = parent;
        if (0 == ps) {
            apnode = new TreeNode(preorder[0]);
        } else {
            if (left) {
                apnode->left = new TreeNode(preorder[ps]);
                apnode = apnode->left;
            } else {
                apnode->right = new TreeNode(preorder[ps]);
                apnode = apnode->right;
            }
        }
        if (ps == pe) {
            // Last node appended
            return apnode;
        }
        // Find root node in inorder
        int index = imp[preorder[ps]];
        // Find left and right range in preorder
        if (is < index) {
            build(preorder, ps + 1, ps + 1 + index - is - 1, inorder, is, index - 1, apnode, true, imp);
        }
        if (ie > index) {
            build(preorder, pe - (ie - index - 1), pe, inorder, index + 1, ie, apnode, false, imp);
        }

        return apnode;
    }
};

#endif

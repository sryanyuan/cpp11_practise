/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (47.66%)
 * Total Accepted:    97.3K
 * Total Submissions: 204.2K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called the "root." Besides the root, each
 * house has one and only one parent house. After a tour, the smart thief
 * realized that "all houses in this place forms a binary tree". It will
 * automatically contact the police if two directly-linked houses were broken
 * into on the same night.
 * 
 * Determine the maximum amount of money the thief can rob tonight without
 * alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3,null,3,null,1]
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \ 
 * ⁠    3   1
 * 
 * Output: 7 
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,5,1,3,null,1]
 * 
 * 3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \ 
 * ⁠1   3   1
 * 
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#ifndef _337_INC_HOUSE_ROBBER_III_
#define _337_INC_HOUSE_ROBBER_III_

#include "_common_binary_tree.h"

class HouseRobberIII337 : public TreeNodeCls {
public:
    static void test() {
        auto tree = stringToTreeNode("[3,2,3,null,3,null,1]");
        auto res = rob(tree);

        tree = stringToTreeNode("[3,4,5,1,3,null,1]");
        res = rob(tree);
    }

    static int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> um;
        return dfs(root, um);
    }

    static int dfs(TreeNode* root, unordered_map<TreeNode*, int> &rvm) {
        if (nullptr == root) {
            return 0;
        }
        if (rvm.count(root) != 0) {
            return rvm[root];
        }
  
        int nVal = root->val;
        if (nullptr != root->left) {
            nVal += dfs(root->left->left, rvm);
            nVal += dfs(root->left->right, rvm);
        }
        if (nullptr != root->right) {
            nVal += dfs(root->right->left, rvm);
            nVal += dfs(root->right->right, rvm);
        }
        nVal = std::max(nVal, dfs(root->left, rvm) + dfs(root->right, rvm));

        rvm[root] = nVal;
        return nVal;
    }
};

#endif

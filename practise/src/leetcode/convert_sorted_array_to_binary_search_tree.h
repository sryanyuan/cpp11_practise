#ifndef _INC_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_
#define _INC_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_

#include <vector>
using std::vector;

/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

0
/ \
-3   9
/   /
-10  5
*/

class ConvertSortedArrayToBinarySearchTree {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    static void test() {
        vector<int> nums;
        int vals[] = {-10, -3, 0, 5, 9};
        for (int i = 0; i < sizeof(vals) / sizeof(vals[0]); i++) {
            nums.push_back(vals[i]);
        }

        auto ret = main(nums);
    }

    static TreeNode* main(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }

        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        build(0, mid - 1, nums, root, true);
        build(mid + 1, nums.size() - 1, nums, root, false);
        return root;
    }

    static void build(int si, int ei, vector<int>& nums, TreeNode* parent, bool left) {
        if (si > ei) {
            return;
        }
        // Find the mid element
        int mid = (si + ei) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        if (left) {
            parent->left = node;
        } else {
            parent->right = node;
        }
        build(si, mid - 1, nums, node, true);
        build(mid + 1, ei, nums, node, false);
    }
};

#endif

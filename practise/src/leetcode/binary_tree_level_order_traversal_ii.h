#ifndef _INC_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_
#define _INC_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_

#include <vector>
using std::vector;
#include <list>
using std::list;

/*
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
[15,7],
[9,20],
[3]
]
*/

class BinaryTreeLevelOrderTraversalII {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    static void test() {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);

        TreeNode* child = root->right;
        child->left = new TreeNode(15);
        child->right = new TreeNode(7);

        auto ret = main(root);
    }

    static vector<vector<int>> main(TreeNode* root) {
        if (nullptr == root) {
            return vector<vector<int>>();
        }

        vector<vector<int>> rets;
        list<TreeNode*> prevNodes;
        prevNodes.push_back(root);
        auto bit = prevNodes.begin();
        int prevDepthCnt = 1;

        while (bit != prevNodes.end()) {
            int cnt = 0;
            auto nit = bit;
            prevNodes.push_back(nullptr);

            for (int i = 0; i < prevDepthCnt; i++) {
                TreeNode* node = *bit;
                if (nullptr != node->right) {
                    prevNodes.push_back(node->right);
                    if (0 == cnt) {
                        // The first push back, mark it as the next loop begin iterator
                        nit = prevNodes.end();
                        nit--;
                    }
                    cnt++;
                }
                if (nullptr != node->left) {
                    prevNodes.push_back(node->left);
                    if (0 == cnt) {
                        // The first push back, mark it as the next loop begin iterator
                        nit = prevNodes.end();
                        nit--;
                    }
                    cnt++;
                }
                bit++;
            }

            // If no child node push back, clear the tail nullptr
            if (0 == cnt) {
                prevNodes.pop_back();
                bit = prevNodes.end();
            } else {
                bit = nit;
                prevDepthCnt = cnt;
            }
        }

        vector<int> depthVals;
        for (auto it = prevNodes.rbegin(); it != prevNodes.rend(); it++) {
            TreeNode* node = *it;
            if (node == nullptr) {
                // Change the owner ship, avoid copy constructor
                rets.push_back(std::move(depthVals));
            } else {
                depthVals.push_back(node->val);
            }
        }
        // Push root value
        if (!depthVals.empty()) {
            rets.push_back(std::move(depthVals));
        }

        return rets;
    }
};

#endif

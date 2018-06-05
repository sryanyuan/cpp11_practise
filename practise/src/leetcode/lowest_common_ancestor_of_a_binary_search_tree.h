#ifndef _INC_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_
#define _INC_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_

#include <stack>
using std::stack;

class LowestCommonAncestorOfABinarySearchTree {
private:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

public:
	static void test() {
		TreeNode* root = new TreeNode(6);
		root->left = new TreeNode(2);
		root->right = new TreeNode(8);
		auto ret = main(root, root->left, root->right);
	}

	static TreeNode* main(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* ppath = root;
		TreeNode* qpath = root;

		while (ppath == qpath) {
			TreeNode* nextp = ppath;
			if (ppath != p) {
				if (p->val < ppath->val) {
					nextp = ppath->left;
				}
				else {
					nextp = ppath->right;
				}
			}

			TreeNode* nextq = qpath;
			if (qpath != q) {
				if (q->val < qpath->val) {
					nextq = qpath->left;
				}
				else {
					nextq = qpath->right;
				}
			}

			if (nextq != nextp) {
				return ppath;
			}
			ppath = nextp;
			qpath = nextq;
		}

		return nullptr;
	}

	static TreeNode* complexMethod(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> parents;

		bool qfound = false, pfound = false;
		TreeNode* ppath = root;
		TreeNode* qpath = root;
		// Finding the p node
		while (!qfound || !pfound) {
			if (!pfound) {
				parents.push(ppath);
				if (ppath->val == p->val) {
					pfound = true;
					continue;
				}
				if (p->val < ppath->val) {
					ppath = ppath->left;
				}
				else {
					ppath = ppath->right;
				}
			}
			if (!qfound) {
				parents.push(qpath);
				if (qpath->val == q->val) {
					qfound = true;
					continue;
				}
				if (q->val < qpath->val) {
					qpath = qpath->left;
				}
				else {
					qpath = qpath->right;
				}
			}
		}
		TreeNode* pre = parents.top();
		parents.pop();

		while (!parents.empty()) {
			TreeNode* cur = parents.top();
			parents.pop();

			if (cur == pre) {
				return cur;
			}
			pre = cur;
		}

		return nullptr;
	}
};

#endif

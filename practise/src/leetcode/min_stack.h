#ifndef _INC_MIN_STACK_
#define _INC_MIN_STACK_

#include <stack>
using std::stack;

class MinStackDoubleLinkedList {
public:
	static void test() {
		MinStackDoubleLinkedList* obj = new MinStackDoubleLinkedList();
		obj->push(-2);
		obj->push(0);
		obj->push(-3);
		
		auto ret = obj->getMin();
		obj->pop();
		ret = obj->top();
		ret = obj->getMin();
	}

private:
	struct Node {
		int val;
		Node* prev;
		Node* next;

		Node(int v) {
			prev = nullptr;
			next = nullptr;
			val = v;
		}
	};

public:
	/** initialize your data structure here. */
	MinStackDoubleLinkedList() {
		head = nullptr;
	}

	void push(int x) {
		Node* nn = new Node(x);
		nodes.push(nn);

		if (nullptr == head) {
			head = nn;
			return;
		}

		Node* node = head;
		while (nullptr != node) {
			if (x < node->val) {
				// Append to head
				nn->next = node;
				node->prev = nn;
				if (node != head) {
					node->prev->next = nn;
					nn->prev = node->prev;
				} else {
					head = nn;
				}
				return;
			}
			if (node->next == nullptr) {
				node->next = nn;
				nn->prev = node;
				return;
			}
			node = node->next;
		}
	}

	void pop() {
		if (nodes.empty()) {
			return;
		}
		if (nodes.size() == 1) {
			delete nodes.top();
			nodes.pop();
			head = nullptr;
			return;
		}
		Node* node = nodes.top();
		nodes.pop();

		if (node->prev == nullptr) {
			node->next->prev = nullptr;
			head = node->next;
		} else if (node->next == nullptr) {
			node->prev->next = nullptr;
		} else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		delete node;
	}

	int top() {
		if (nodes.empty()) {
			return 0;
		}
		return nodes.top()->val;
	}

	int getMin() {
		if (head == nullptr) {
			return 0;
		}
		return head->val;
	}
	/**
	* Your MinStack object will be instantiated and called as such:
	* MinStack obj = new MinStack();
	* obj.push(x);
	* obj.pop();
	* int param_3 = obj.top();
	* int param_4 = obj.getMin();
	*/

	stack<Node*> nodes;
	Node* head;
};

#endif

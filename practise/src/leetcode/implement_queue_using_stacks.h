#ifndef _INC_IMPLEMENT_QUEUE_USING_STACKS_
#define _INC_IMPLEMENT_QUEUE_USING_STACKS_

#include <stack>
using std::stack;

class ImplementQueueUsingStacks {
public:
    class MyQueue {
    public:
        /** Initialize your data structure here. */
        MyQueue() {
            
        }

        /** Push element x to the back of queue. */
        void push(int x) {
            stk_.push(x);
        }

        /** Removes the element from in front of queue and returns that element. */
        int pop() {
            borrow();
            int val = stkb_.top();
            stkb_.pop();
            return val;
        }

        /** Get the front element. */
        int peek() {
            borrow();
            return stkb_.top();
        }

        /** Returns whether the queue is empty. */
        bool empty() {
            return stk_.empty() && stkb_.empty();
        }

        void borrow() {
            if (stkb_.empty()) {
                while (!stk_.empty()) {
                    int val = stk_.top();
                    stk_.pop();
                    stkb_.push(val);
                }
            }
        }

    private:
        std::stack<int> stk_;
        std::stack<int> stkb_;
    };
};

#endif

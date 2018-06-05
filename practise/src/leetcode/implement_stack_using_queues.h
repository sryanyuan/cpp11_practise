#ifndef _INC_IMPLEMENT_STACK_USING_QUEUES_
#define _INC_IMPLEMENT_STACK_USING_QUEUES_

#include <list>
using std::list;

class ImplementStackUsingQueues {
public:
    static void test() {
        MyStack stk;
        stk.push(1);
        stk.push(2);
        auto v = stk.pop();
        v = stk.top();
    }

    class MyStack {
    public:
        /** Initialize your data structure here. */
        MyStack() {

        }

        /** Push element x onto stack. */
        void push(int x) {
            q_.push_back(x);
        }

        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            int val = q_.back();
            q_.pop_back();
            return val;
        }

        /** Get the top element. */
        int top() {
            int val = q_.back();
            return val;
        }

        /** Returns whether the stack is empty. */
        bool empty() {
            return q_.empty();
        }

    private:
        list<int> q_;
    };
};

#endif

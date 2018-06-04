#ifndef _INC_MIN_STACK__
#define _INC_MIN_STACK__

#include <stack>
using std::stack;

class MinStack_ {
public:
    static void test() {
        MinStack_ stk;
        stk.push(0);
        stk.push(1);
        stk.push(0);

        auto ret = stk.getMin();
        stk.pop();
        ret = stk.getMin();
    }

public:
    /** initialize your data structure here. */
    MinStack_() {
        min_val_ = 2147483647;
    }

    void push(int x) {
        if (x <= min_val_) {
            // Push the original min value and update the min value with x
            stk_.push(min_val_);
            min_val_ = x;
        }
        stk_.push(x);
    }

    void pop() {
        if (stk_.empty()) {
            return;
        }
        // If top is min value, pop and pop to get the previous min value before top min value
        int val = stk_.top();
        stk_.pop();
        if (val == min_val_) {
            min_val_ = stk_.top();
            stk_.pop();
        }
    }

    int top() {
        return stk_.top();
    }

    int getMin() {
        return min_val_;
    } 

private:
    stack<int> stk_;
    int min_val_;

    /**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
};

#endif
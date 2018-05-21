#ifndef _INC_BLOCKING_QUEUE_
#define _INC_BLOCKING_QUEUE_

#include "../utils/mutex_lock_guard.h"

#include <deque>
#include <condition_variable>
#include <mutex>

using std::deque;
using std::condition_variable;
using std::mutex;

// T is better to implement the operator= and copy instructor with T&& right reference
// type to reduce the copy cost.
template <typename T>
class BlockingQueue {
public:
    typedef deque<T> tdeque;

public:
    T get() {
        std::unique_lock<std::mutex> lock(mu_);
        while (que_.empty()) {
            // Go on sleeping
            cond_.wait(lock);
            // If wakeup, cond_ will hold the mutex, so it is safe to access
            // the que_
        }
        
        T task = std::move(que_.front());
        que_.pop_back();
        return task;
    }

    void put(T& task) {
        std::unique_lock<std::mutex> lock(mu_);

        que_.push_back(task);
        cond_.notify_one();
    }

    void put(T&& task) {
        std::unique_lock<std::mutex> lock(mu_);

        que_.push_back(std::move(task));
        cond_.notify_one();
    }

private:
    tdeque que_;
    mutex mu_;
    condition_variable cond_;
};

#endif

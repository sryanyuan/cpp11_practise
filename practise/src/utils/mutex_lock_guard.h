#ifndef _INC_MUTEX_LOCK_GUARD_
#define _INC_MUTEX_LOCK_GUARD_

#include <mutex>

class MutexLockGuard {
public:
    explicit MutexLockGuard(std::mutex& mu) : mutex_(mu) {
        mutex_.lock();
    }
    ~MutexLockGuard() {
        mutex_.unlock();
    }

private:
    std::mutex& mutex_;
};

#endif
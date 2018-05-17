#ifndef _INC_WEAKCALLBACK_
#define _INC_WEAKCALLBACK_

#include <memory>
#include <map>
#include <mutex>

class WeakItem {
public:
    WeakItem() {
        value_ = 0;
    }
    ~WeakItem() {

    }

private:
    int value_;
};

class WeakFactory : public std::enable_shared_from_this<WeakFactory>
{
public:
    WeakFactory() {

    }
    ~WeakFactory() {

    }

public:

    std::shared_ptr<WeakItem> get(std::string key) {
        lock_.lock();
        auto& wptr = items_[key];
        auto sptr = wptr.lock();
        if (nullptr == sptr) {
            // Not allocated
            sptr = std::shared_ptr<WeakItem>(new WeakItem);
            // To weak_ptr
            wptr = sptr;
        }
        lock_.unlock();

        return sptr;
    }

    void free_item(std::weak_ptr<WeakItem> ptr) {
        auto sptr = ptr.lock();
        if (nullptr == sptr) {
            //
        }
    }

private:
    // Save as weak_ptr rather than shared_ptr
    // If we use the shared_ptr, items_ will always hold the shared_ptr
    // and items referenced won't be deleted by shared_ptr
    std::map<std::string, std::weak_ptr<WeakItem> > items_;
    std::mutex lock_;
};

#endif
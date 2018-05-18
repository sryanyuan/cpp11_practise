#ifndef _INC_WEAKCALLBACK_
#define _INC_WEAKCALLBACK_

#include <memory>
#include <map>
#include <mutex>
#include <atomic>
#include <thread>
#include <string>
#include <functional>
#include <stdio.h>

class WeakItem {
public:
    WeakItem() {
        value_ = 0;
    }
    ~WeakItem() {
        printf("delete item key %s\r\n", key_.c_str());
    }

public:
    int value_;
    std::string key_;
};

class WeakFactory : public std::enable_shared_from_this<WeakFactory>
{
public:
    WeakFactory() {

    }
    ~WeakFactory() {
        printf("delete factory, left item %d\r\n", items_.size());
    }

public:

    std::shared_ptr<WeakItem> get(std::string key) {
        lock_.lock();
        auto& wptr = items_[key];
        auto sptr = wptr.lock();
        if (nullptr == sptr) {
            // Not allocated
            sptr = std::shared_ptr<WeakItem>(new WeakItem, 
                std::bind(&WeakFactory::free_item, 
                std::weak_ptr<WeakFactory>(shared_from_this()), 
                std::placeholders::_1));
            sptr->value_ = 0;
            sptr->key_ = key;
            // To weak_ptr
            wptr = sptr;
        }
        lock_.unlock();

        return sptr;
    }

public:
    static void main(int argc, char* argv[]) {
        std::shared_ptr<WeakItem> powned_item;

        {
            // Factory scope
            std::shared_ptr<WeakFactory> pfac(new WeakFactory);
            powned_item = pfac->get("owned");

            auto tfunc = [pfac]() {
                for (int i = 0; i < 100; i++) {
                    char buf[8] = {0};
                    sprintf(buf, "%d", i);
                    std::string key = buf;
                    auto item = pfac->get(key);
                    // We do not use it any more out of this scope,
                    // So item will be released by shared_ptr immediately
                }
            };
            std::thread t1(tfunc);
            std::thread t2(tfunc);

            t1.join();
            t2.join();
        }
        
        // Factory is deleted, owned_item should be delete but not erase from factory
        // ...
    }

private:

    void delete_from_internal(WeakItem* old) {
        lock_.lock();
        items_.erase(old->key_);
        lock_.unlock();
    }

    // We declare a static function to release the WeakItem
    static void free_item(std::weak_ptr<WeakFactory> ptr, WeakItem* old) {
        auto sptr = ptr.lock();
        if (nullptr != sptr) {
            sptr->delete_from_internal(old);
        } else {
            printf("factory is deleted ..., item %s not erased from items_\r\n",
                old->key_.c_str());
        }
        
        delete old;
        old = nullptr;
    }

private:
    // Save as weak_ptr rather than shared_ptr
    // If we use the shared_ptr, items_ will always hold the shared_ptr
    // and items referenced won't be deleted by shared_ptr
    std::map<std::string, std::weak_ptr<WeakItem> > items_;
    std::mutex lock_;
};

#endif

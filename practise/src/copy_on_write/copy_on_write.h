#ifndef _INC_COPY_ON_WRITE_
#define _INC_COPY_ON_WRITE_

#include <atomic>
#include <memory>
#include <list>
#include <mutex>
#include <functional>
#include <thread>
#include <chrono>

struct COWTask {
    int id;

    COWTask() {
        id = 0;
    }
};

typedef std::list<COWTask> COWTaskList;

class CopyOnWrite {
public:
    CopyOnWrite() :
    queue_(new COWTaskList) {
        copy_times_ = 0;
    }

    ~CopyOnWrite() {
        printf("%s\r\n", __FUNCTION__);
    }

public:
    void read() {
        std::shared_ptr<COWTaskList> tptr;
        // Read the pointer to make a copy and increase the reference count
        {
            qmu_.lock();
            tptr = queue_;
            qmu_.unlock();
        }

        // To traverse the list
        // tptr is point to the original list, and queue_ may be a new list if 
        // write is called
        printf("Task ");
        for (auto& task : *tptr) {
            printf("%d ", task.id);
        }
        printf("\r\n");
    }

    void write(const COWTask& task) {
        qmu_.lock();
        // Check reference
        if (!queue_.unique()) {
            // Read in progress, make a copy
            queue_.reset(new COWTaskList(*queue_));
            copy_times_++;
        } else {
            // No read, just push to queue
        }
        if (queue_->size() > 5) {
            queue_->pop_front();
        }
        queue_->push_back(task);
        qmu_.unlock();
    }

public:
    static int main(int argc, char* argv[]) {
        std::atomic<int> id_seed = 0;
        std::shared_ptr<CopyOnWrite> ins(new CopyOnWrite);
        std::thread t1([ins, &id_seed]() {
            // Reader
            for (int i = 0; i < 1000; i++) {
                ins->read();
                std::this_thread::sleep_for(std::chrono::milliseconds(11));
            }
            printf("read done\r\n");
        });
        std::thread t2([ins, &id_seed]() {
            // Writer
            for (int i = 0; i < 1000; i++) {
                COWTask task;
                task.id = id_seed++;
                ins->write(task);
                std::this_thread::sleep_for(std::chrono::milliseconds(7));
            }
            printf("write done\r\n");
        });

        t1.join();
        t2.join();

        printf("copy times %d\r\n", ins->copy_times_);

        return 0;
    }

private:
    std::atomic<int> copy_times_;
    std::shared_ptr<COWTaskList> queue_;
    std::mutex qmu_;
};

#endif

#include "blocking_queue.h"

#include <thread>

using std::thread;

class MyTask {
public:
    MyTask() {
        printf("%s\r\n", __FUNCTION__);
        data_ = nullptr;
    }
    MyTask(const MyTask& task) {
        data_ = nullptr;
        printf("%s&\r\n", __FUNCTION__);
        if (&task == this) {
            return;
        }
        set(task.data_);
    }
    MyTask(MyTask&& task) {
        data_ = nullptr;
        printf("%s&&\r\n", __FUNCTION__);
        data_ = task.data_;
        task.data_ = nullptr;
    }

    ~MyTask() {
        if (nullptr != data_) {
             printf("%s %s \r\n", __FUNCTION__, data_);
        } else {
             printf("%s null\r\n", __FUNCTION__);
        }
       
        delete []data_;
        data_ = nullptr;
    }

    MyTask& operator=(const MyTask& task) {
        printf("%s&\r\n", __FUNCTION__);
        if (&task == this) {
            return *this;
        }
        set(task.data_);
    }
    MyTask& operator=(MyTask&& task) {
        printf("%s&&\r\n", __FUNCTION__);
        data_ = task.data_;
        task.data_ = nullptr;
        return *this;
    }

public:
    void set(char *data) {
        size_t len = strlen(data);
        if (nullptr != data_) {
            delete [] data_;
            data_ = nullptr;
        }
        data_ = (char*)malloc(len + 1);
        strcpy(data_, data);
    }

    char* get() {
        return data_;
    }

private:
    // Terminate with \0
    char* data_;
};

int blocking_queue_test_overview() {
    BlockingQueue<MyTask> q;
    int cnt = 1;

    thread thread_reader([&q, cnt](){
        for (int i = 0; i < cnt; i++) {
            MyTask mt;
            char buf[11];
            sprintf(buf, "task_0_%d", i);
            mt.set(buf);
            q.put(std::move(mt));
            std::this_thread::sleep_for(std::chrono::milliseconds(11));
        }
    });
    thread thread_writer([&q, cnt](){
        int i = 0;
        MyTask task;

        for (;;) {
            task = q.get();
            i++;
            printf("got %s\r\n", task.get());
            if (i >= cnt) {
                break;
            }
        }
    });

    thread_reader.join();
    thread_writer.join();

    return 0;
}

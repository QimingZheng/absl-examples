#include <iostream>
#include <string>
#include <vector>
#include <thread>

#include "absl/synchronization/barrier.h"
#include "absl/synchronization/mutex.h"
#include "absl/synchronization/notification.h"
#include "absl/synchronization/blocking_counter.h"

absl::Mutex mtx;
absl::CondVar cv;
int counter = 0;

void thread1() {
    mtx.Lock();
    counter += 1;
    mtx.Unlock();
    std::cout << "thread 1 exits\n";
}

void thread2() {
    mtx.Lock();
    auto counter_is_one = [&] { return counter == 1; };
    mtx.Await(absl::Condition(&counter_is_one));
    mtx.Unlock();
    std::cout << "thread 2 exits\n";
}

void cook() {
    mtx.Lock();
    counter = 8;
    cv.SignalAll();
    mtx.Unlock();
    std::cout << "cook thread exit\n";
}

void eat() {
    mtx.Lock();
    if (counter == 0) {
        cv.Wait(&mtx);
    }
    std::cout << "eat thread exit\n";
    mtx.Unlock();
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);
    t1.join();
    t2.join();
    t1 = std::thread(cook);
    std::vector<std::thread> t(8);
    for (int i = 0; i < 8; i++) {
        t[i] = std::thread(eat);
    }
    t1.join();
    for (int i = 0; i < 8; i++) t[i].join();
    return 0;
}
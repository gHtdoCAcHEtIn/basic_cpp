
#include <iostream>
#include <string>
#include <queue>
#include <chrono>
#include <thread>
#include <pthread.h>

#define N_TASKS 3
#define N_DATA 100

using namespace std;
using Clock = std::chrono::steady_clock;

std::queue<int> queue_0;
std::queue<int> queue_1;
std::queue<int> queue_2;

void* task0(void* arg) {
    for (int i = 0; i < N_DATA; i++)
        queue_0.push(i);
    return NULL;
}

void* task1(void* arg) {
    while(!queue_0.empty()) {
        int item = queue_0.front();
        item *= 2;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        queue_1.push(item);
        queue_0.pop();
    }
    return NULL;
}

void* task2(void* arg) {
    while(!queue_1.empty()) {
        int item = queue_1.front();
        item *= 3;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        queue_2.push(item);
        queue_1.pop();
    }
    return NULL;
}

void test_queue() {
    std::queue<int> q1;
    std::cout<<q1.size();
    q1.push(1);
    std::cout<<q1.size();
    q1.pop();
    std::cout<<q1.size();
    q1.push(1);
    std::cout<<q1.size();
    int x = q1.front();
    std::cout<<q1.size();
    
}
void process_with_threads(void* (*tasks[N_TASKS]) (void *)) {
    // init threads ids
    pthread_t tId[N_TASKS];
    int err = 0;
    // Create threads
    for (int i = 0; i < N_TASKS; i++) {
        err = pthread_create(&tId[i], NULL, tasks[i], NULL);
        // Check if thread is created successfuly
        if (err) {
            //std::cout << "Thread creation failed : " << strerror(err);
            return;
        }
        else {
            //std::cout << "Thread Created with ID : " << tId[i] << std::endl;
            
        }
    }
    //Join threads
    for (int i = 0; i < N_TASKS; i++) {
        err = pthread_join(tId[i], NULL);
        // check if joining is successful
        if (err) {
            //std::cout << "Failed to join Thread : " << strerror(err) << std::endl;
            return;
        }
    }
}

void process_without_threads(void* (*tasks[N_TASKS]) (void *)) {
    for (int i = 0; i < N_TASKS; i++)
        (*tasks[i]) (NULL);
}
void print_values() {
    /*std::cout << "input queue 0" << std::endl;
    while(!queue_1.empty()) {
        int item = queue_1.front();
        std::cout << item << std::endl;
        queue_1.pop();
    }*/
    
    /*std::cout << "intermediate queue 1" << std::endl;
    while(!queue_1.empty()) {
        int item = queue_1.front();
        std::cout << item << std::endl;
        queue_1.pop();
    }*/
    
    std::cout << "output queue 2" << std::endl;
    while(!queue_2.empty()) {
        int item = queue_2.front();
        std::cout << item << std::endl;
        queue_2.pop();
    }
}
int main() {
    std::chrono::time_point<Clock> start, end;
    std::chrono::milliseconds diff;
    
    void* (*tasks[N_TASKS]) (void*) = {&task0, &task1, &task2}; 
    // function pointer: void* (*taskfn) (void*) taskfn is a func pointer, return type=void*, argument=void*
    // array of func pointers: void* (*taskfn[N]) (void*)
    
    std::cout << "without threads" << std::endl;
    start = Clock::now();
    process_without_threads(tasks);
    end = Clock::now();
    //diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << diff.count() << "ms" << std::endl;
    print_values();
    
    std::cout << "with threads" << std::endl;
    start = Clock::now();
    process_with_threads(tasks);
    end = Clock::now();
    diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << diff.count() << "ms" << std::endl;
    print_values();
    
    std::cout << "exiting main()" << std::endl;

    return 1;
}

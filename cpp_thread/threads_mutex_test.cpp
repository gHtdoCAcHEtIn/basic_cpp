#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include <mutex>

struct SharedResource{
  std::mutex m;
};
SharedResource GPU;

void testFn(int i) {
  //preprocess
  std::this_thread::sleep_for(
       std::chrono::milliseconds(300));

  //gpu
  GPU.m.lock();

  std::this_thread::sleep_for(
       std::chrono::milliseconds(400)); 

  GPU.m.unlock();

  //post process
  std::this_thread::sleep_for(
       std::chrono::milliseconds(300)); 

}

void threads_mutex_test(int numThreads) {
  std::vector<std::thread> threads;

  // start time
  auto start = std::chrono::high_resolution_clock::now();

  //start threads
  for(int i = 0; i < numThreads; i++)
    threads.push_back(std::thread(testFn, i));
   // add delay to simulate input data speed

  // finish threads
  for(int i = 0; i < numThreads; i ++)
    threads[i].join();

  // end time
  auto end = std::chrono::high_resolution_clock::now();
  
  std::chrono::duration<double> diff = end-start;
  std::cout << "NumThreads: " << numThreads << ": ";
  std::cout << "Latency: " <<  diff.count() << "s, ";
  std::cout << "FPS: " << numThreads / diff.count() << std::endl;
  
}

int main(int argc, char **argv) {
  int nThreads;
  nThreads = (argc < 2) ? 5 : atoi(argv[1]);
  for (int i = 1; i <= nThreads; ++i)
    threads_mutex_test(i);
  return 0;
}

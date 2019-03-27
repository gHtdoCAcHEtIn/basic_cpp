#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include <mutex>

struct SharedResource{
  std::mutex m;
};
SharedResource GPU;

void testFn(int start, int numJobs, int numThreads) {
  for(int i = start; i < numJobs; i += numThreads) {
    i;
    
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

}

void threads_mutex_test(int numJobs, int numThreads) {
  std::vector<std::thread> threads(numThreads);

  // start time
  auto t_start = std::chrono::high_resolution_clock::now();

  //start threads
  for(int i = 0; i < numThreads; ++i) {
    threads[i] = std::thread(testFn, i, numJobs, numThreads);
    // add delay to simulate input data speed
  }

  // finish threads
  for(int i = 0; i < numThreads; ++i)
    threads[i].join();

  // end time
  auto t_end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = t_end - t_start;

  std::cout << "NumJobs: " << numJobs << ": ";
  std::cout << "NumThreads: " << numThreads << ": ";
  std::cout << "Latency: " <<  diff.count() << "s, ";
  std::cout << "FPS: " << numJobs / diff.count() << std::endl;
  
}

int main(int argc, char **argv) {
  int nJobs, nThreads;

  nJobs = (argc < 2) ? 5 : atoi(argv[1]);
  nThreads = (argc < 3) ? 5 : atoi(argv[2]);

  for (int i = 1; i <= nThreads; ++i)
    threads_mutex_test(nJobs, i);
  return 0;
}


#include <iostream>
#include <chrono>
#include <vector>
#include <thread>

void testFn(int start, int numJobs, int numThreads) {
  for(int i = start; i < numJobs; i += numThreads) {
    //preprocess | gpu | post process
    i;
    std::this_thread::sleep_for(
       std::chrono::milliseconds(1000));
  
  }
}

void threads_test(int numJobs, int numThreads) {
  std::vector<std::thread> threads(numThreads);
  
  // time measurement - start
  auto t_start = std::chrono::high_resolution_clock::now();

  //start threads
  for(int i = 0; i < numThreads; ++i) {
    int start = i * numThreads;
    threads[i] = std::thread(testFn, start, numJobs, numThreads);
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

  for (int iThreads = 1; iThreads <= nThreads; ++iThreads)
    threads_test(nJobs, iThreads);
  
  return 0;
}


#include <iostream>
#include <chrono>
#include <vector>
#include <thread>

void testFn(int i) {
  std::this_thread::sleep_for(
       std::chrono::milliseconds(1000)); 
  //std::cout << "i=" << i << std::endl;
}

void threads_test(int numThreads) {
  
  std::vector<std::thread> threads;
  auto start = std::chrono::high_resolution_clock::now();
  for(int i = 0;i < numThreads; i++)
    threads.push_back(std::thread(testFn, i));
  for(int i = 0; i < numThreads; i ++)
    threads[i].join();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end-start;
  std::cout << "NumThreads: " << numThreads << ": ";
  std::cout << "Latency: " <<  diff.count() << "s, ";
  std::cout << "FPS: " << numThreads / diff.count() << std::endl;
  
}

int main(int argc, char **argv) {
  int n;
  char *n_str = argv[1];
  if (n_str == NULL)
    n = 5;
  else
    n = atoi(argv[1]);
  for(int i = 1; i <= n; i++)
    threads_test(i);
  return 0;
}

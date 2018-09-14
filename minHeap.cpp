#include <iostream>

// minHeap.cpp
// maxHeap.cpp

// member utilities
// int parent(int i)
// int left(int i)
// int right(int i)

// member functions
// minHeap(int a[], int size)
//  save a pointer
//  mark heapSize = size
// minHeapify(int i)
/*  heapify at index i
    if a[i] > a[left] && a[i] > a[right]
      return;
    else
      minHeapify(min(i, left, right))
*/

//T is the data type of heap elements
template<typename T> class heap { 
  protected:
    T *heapData;
    int heapSize;

    int parent(int idx) {
        return (idx + 1) / 2 - 1; 
    }
    int leftChild(int idx) { 
        return 2 * (idx + 1) - 1; 
    }
    int rightChild(int idx) { 
        return 2 * (idx + 1);
    }
  public:
    void setHeapData(T *inputData) {
      heapData = inputData;
    }
    
    void setHeapSize(int size) {
      heapSize = size;
    }
};
// changing to public heap<int> does not work
template<typename T>
class minHeap : public heap<int> {
  public:
    void minHeapify(int i) {
      std::cout << i << std::endl;
      if (!(i < heapSize))
        return;
      int smallest = i;
      if (leftChild(i) < heapSize) {
        if (heapData[leftChild(i)] < heapData[smallest]) {
          smallest = leftChild(i);
        }
      }
      if (rightChild(i) < heapSize) {
        if (heapData[rightChild(i)] < heapData[smallest]) {
          smallest = rightChild(i);
        }
      }
      if (smallest !=  i) {
        int temp;
        std::cout << "swapping : " << heapData[i] << ", " << heapData[smallest] << std::endl;
        temp = heapData[i];
        heapData[i] = heapData[smallest];
        heapData[smallest] = temp;
        minHeapify(smallest);
      }
    }
};



/* TEST MAIN */
int main() {
  std::cout << "Hello \n";
  
  int a[] = {7,2,3,4,5,6,1};
  //heap<int> h;
  //h.setHeapData(a);
  //h.setHeapSize(7);
  minHeap<int> mh;
  mh.setHeapData(a);
  mh.setHeapSize(7);
  
  for (int i = 0; i < 7; i++)
    std::cout << a[i] << ",";
  std::cout << std::endl;
  
  mh.minHeapify(0);
  
  for (int i = 0; i < 7; i++)
    std::cout << a[i] << ",";
  std::cout << std::endl;
  
  return 0;
}





// Example program
#include <iostream>
#include <string>
#include <climits>

/* INSERTION SORT */
template<typename T>
void insertionSort(T array[], int length) {
    int i, j;
    for(i = 1; i < length; i++) {
        T curr = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > curr) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = curr;
    }
    
}

/* BUBBLE SORT */
template<typename T>
void bubbleSort(T array[], int length) {
    int i, j;
    T tmp;
    for(i = 0; i < length - 1; i++) {
        for (j = length - 1; j > i; j--) {
            if (array[j] < array[j - 1]) {
                //swap a[j], a[j - 1]
                tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }
        }
    }    
}

/* MERGE SORT */
template<typename T>
void merge(T array[], int left, int mid, int right) {
    int i, j, k;
    
    T *LeftSeq = new T[mid - left + 1];
    T *RightSeq = new T[right - mid + 1];
        
    for (i = 0; i < mid - left; i++) 
        LeftSeq[i] = array[left + i];
    LeftSeq[i] = INT_MAX;
    
    for (j = 0; j < right - mid; j++)
        RightSeq[j] = array[mid + j];
    RightSeq[j] = INT_MAX;
    
    i = 0;
    j = 0;
    k = left;
    while (k < right) {
        if (LeftSeq[i] < RightSeq[j]) 
            array[k++] = LeftSeq[i++];
        else 
            array[k++] = RightSeq[j++];
    }
}

template<typename T>
void mergeSort(T array[], int left, int right) {
    if (left < right - 1) {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid, right);
        merge(array, left, mid, right);
    }
}

/* TEST MAIN */
int main()
{
  std::cout << "Hello" << "!\n";
  int test1[] = {5, 9, 8, 7, 1, 1, 2, 3, 4, 9, 8};
  //insertionSort(test1, 11);
  //mergeSort(test1, 0, 10);
  bubbleSort(test1, 11);
  for(int i = 0; i < 11; i++)
      std::cout << test1[i] << ",";
  std::cout << "\n";
  return 1;
}

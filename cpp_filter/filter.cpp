#include <iostream>
using namespace std;

class Filter {
  public:
  
  static const int WINDOW = 5;
  float *buffer; // buffer[WINDOW]
  float bufferAverage;
  int bufferIndex;
  
  Filter();
  void insertItemAverage(float reading);
  
  void insertItemMedian(float reading);
  
  float getAverage();
  
  float getMedian();
};


Filter::Filter() {
  buffer = new float[WINDOW];
  for(int i = 0; i < WINDOW; i++) {
    buffer[i] = 0.0;
  }
  bufferIndex = 0;
  bufferAverage = 0.0;
}

void Filter::insertItemAverage(float reading) {
  // remove old reading, subtract from running average
  bufferAverage -= buffer[bufferIndex] / WINDOW;
  
  // store new reading
  buffer[bufferIndex] = reading;

  // move to next index
  bufferIndex = (bufferIndex + 1) % WINDOW;
  
  // add new reading to running average
  bufferAverage += reading / WINDOW;
  
}

float Filter::getAverage() {
  return bufferAverage;
}

int main() {
  cout << "Hello" << endl;
  
  Filter f = Filter();
  f.insertItemAverage(1.0);
  f.insertItemAverage(1.0);
  f.insertItemAverage(1.0);
  f.insertItemAverage(1.0);
  f.insertItemAverage(1.0);
  cout << f.getAverage() << endl;
  
  f = Filter();
  for (int i = 0; i < 10; i++) {
    f.insertItemAverage(1.0);
    if (i % 1 == 0) {
      cout << f.getAverage() << endl;
    }
  }

  cout<<f.getAverage() << endl;
  return 0;
}



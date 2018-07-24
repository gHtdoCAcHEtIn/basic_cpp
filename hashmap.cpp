// Example program
#include <iostream>

/* HASH_NODE */
template<typename K, typename V>
class HashNode {
    private:
        K _key;
        V _value;
        HashNode *_next;
    public:
        HashNode(const K &key, const V &value) :
            _key(key), _value(value), _next(NULL)
        {
        }
        K getKey() {
            return _key;
        }
        V getValue() {
            return _value;
        }
        HashNode * getNext() {
            return _next;
        }
        void setKey(const K &key) {
            _key = key;
        }
        void setNext(HashNode *next) {
            _next = next;
        }
        void setValue(const V &value) {
            _value = value;
        }
};


/* HASH TABLE */
template<typename K, typename V>
class HashMap {
    private:
        HashNode<K, V> **table;
        unsigned long _hashTableLength;
        unsigned long hashFunc(const K &key) {
            return (unsigned long)(key) % _hashTableLength;
        }
    public:
        HashMap(int hashTableLength) :
            _hashTableLength(hashTableLength) 
        {
            table = new HashNode<K, V> *[_hashTableLength];
        }
        
        void put(const K &key, const V &value) {
            unsigned long hashValue = hashFunc(key);
            HashNode<K, V> *prev = NULL;
            HashNode<K, V> *entry = table[hashValue];
            
            while (entry != NULL && entry->getKey() != key) {
                prev = entry;
                entry = entry->getNext();
            }
            
            if (entry == NULL) {
                entry = new HashNode<K, V>(key, value);
                
                if (prev == NULL) 
                    table[hashValue] = entry;
                else
                    prev->setNext(entry);
            }
            else if (entry->getKey() == key) {
                entry->setValue(value);
            }
        }
        int get(const K &key, V &value) {
            unsigned long hashValue = hashFunc(key);
            HashNode<K, V> *entry = table[hashValue];
            
            while(entry != NULL && entry->getKey() != key) {
                entry = entry->getNext();
            }
            
            if (entry == NULL) {
                // key not found
                return -1;
            }
            else {
                value = entry->getValue();
                return 0;
            }
        }
        
};


/* TEST MAIN */
void test1() {
  HashMap<int, int> EmployeeAge(10);
  EmployeeAge.put(1, 34);
  EmployeeAge.put(2, 23);
  EmployeeAge.put(3, 16);
  EmployeeAge.put(4, 38);
  EmployeeAge.put(5, 26);
  EmployeeAge.put(6, 55);
  
  int ret = 0, value = 0;
  ret = EmployeeAge.get(5, value);
  std::cout << ret << ", " << value << std::endl;
  ret = EmployeeAge.get(4, value);
  std::cout << ret << ", " << value << std::endl;
  ret = EmployeeAge.get(3, value);
  std::cout << ret << ", " << value << std::endl;
  ret = EmployeeAge.get(2, value);
  std::cout << ret << ", " << value << std::endl;
  ret = EmployeeAge.get(1, value);
  std::cout << ret << ", " << value << std::endl;

}

void test2() {
  HashMap<char *, int> EmployeeAge(10);
  EmployeeAge.put("1", 34);
  EmployeeAge.put("2", 23);
  EmployeeAge.put("3", 16);
  EmployeeAge.put("4", 38);
  EmployeeAge.put("5", 26);
  EmployeeAge.put("6", 55);
  
  int ret = 0, value = 0;

  ret = EmployeeAge.get("5", value);
  std::cout << ret << ", " << value << std::endl;
  ret = EmployeeAge.get("4", value);
  std::cout << ret << ", " << value << std::endl;
  ret = EmployeeAge.get("3", value);
  std::cout << ret << ", " << value << std::endl;
  ret = EmployeeAge.get("2", value);
  std::cout << ret << ", " << value << std::endl;
  ret = EmployeeAge.get("1", value);
  std::cout << ret << ", " << value << std::endl;
}

int main()
{
  std::cout << "Hello" << "!\n";
  test1();
  test2();
  return 0;
}

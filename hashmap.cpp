// Example program
#include <iostream>
#include <string>


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
        int _hashTableLength;
        unsigned long hashFunc(const K &key) {
            return (unsigned long)(key) % _hashTableLength;
        }
    public:
        HashMap(int HashTableLength) :
            _hashTableLength(HashTableLength) 
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
            
            if (entry->getKey() == key) {
                entry->setValue(value);
            }
            
            else if (entry == NULL) {
                entry = new HashNode<K, V>(key, value);
                
                if (prev == NULL) 
                    table[hashValue] = entry;
                else
                    prev->setNext(entry);
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
int main()
{
  std::cout << "Hello" << "!\n";
  
  HashMap<string, int> EmployeeAge(10);
  /*EmployeeAge.put("Emp1", "34");
  EmployeeAge.put("Emp2", "23");
  EmployeeAge.put("Emp3", "16");
  EmployeeAge.put("Emp4", "38");
  EmployeeAge.put("Emp5", "26");
  EmployeeAge.put("Emp6", "55");
  
  std::cout << EmployeeAge.get("Emp6") << ",";
  std::cout << EmployeeAge.get("Emp5") << ",";
  std::cout << EmployeeAge.get("Emp4") << ",";
  std::cout << EmployeeAge.get("Emp3") << ",";
  std::cout << EmployeeAge.get("Emp2") << ",";
  std::cout << EmployeeAge.get("Emp1") << ",";
  std::cout << "\n";*/
  return 1;
}

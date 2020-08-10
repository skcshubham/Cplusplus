#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

class Hash
{
  int BUCKET;    // Size of hash table of doubly LL 
  list <int>* table; // doubly LL or the chains
public:
  Hash(int b)  // Constructor 
  {
    this->BUCKET = b;
    table = new list<int>[BUCKET];
  }

  // inserts a key into hash table 
  void insertItem(int key)
  {
    int index = hashFunction(key);
    table[index].push_back(key);
  }

  // deletes a key from hash table 
  void deleteItem(int key)
  {
    // get the hash index of key 
    int index = hashFunction(key);

    // find the key using iterator 
    list <int> ::iterator i;
    for (i = table[index].begin();
      i != table[index].end(); i++) {
      if (*i == key)
        break;
    }

    // if key is found in hash table, remove it 
    if (i != table[index].end())
      table[index].erase(i);
  }

  // hash function to map values to key 
  int hashFunction(int x) {
    return (x % BUCKET);
  }

  void displayHash()
  {
    for (int i = 0; i < BUCKET; i++) {
      cout << i;
      for (auto x : table[i])
        cout << " --> " << x;
      cout << endl;
    }
  }
};

int main()
{
  // keys to be mapped 
  int a[] = { 15, 11, 27, 8, 12 };
  int n = sizeof(a) / sizeof(a[0]);

  // insert the keys into the hash table 
  Hash h(7);   // 7 is count of buckets/elements in the hash table

  for (int i = 0; i < n; i++)
    h.insertItem(a[i]);

  // delete 12 from hash table 
  h.deleteItem(12);

  // display the Hash table 
  h.displayHash();

  return 0;
}
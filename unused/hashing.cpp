#include <iostream>
#include <string>
#include <queue>
using namespace std;

class MapADT {
public:
  MapADT();
  MapADT(string filename);

  string find(const string& key);  
  void insert(const string& key, const string& value);
  string remove(const string& key);

  void print();
protected:
  unsigned int hash(const string& key);


  const static unsigned int size_max = 30;
  string keys[size_max];
  string values[size_max];
};

MapADT::MapADT() {
  for (int i = 0; i < size_max; i++) {
    keys[i] = string();
    values[i] = string();
  }
}

unsigned int MapADT::hash(const string& k)
{
  unsigned int value = 0 ;
  for (int i = 0; i < k.length(); i++)
    value = 37*value + k[i];
  return value;
}

void MapADT::print() {
  cout << "{";
  for (int i = 0; i < size_max; i++)
    if (!keys[i].empty())
      cout << keys[i] << ":" << values[i] << ", ";
  cout << "}" << endl;
}



void MapADT::insert(const string& key, const string& value) {
  int index = find_index(key);
  if (index == -1) {
    cerr << "Table is full!" << endl;
    return;
  }

  keys[index] = key;
  values[index] = value;
}

string MapADT::find(const string& key) {
  int index = find_index(key);
  if (index != -1)
    return values[index];

  return "";
}

string MapADT::remove(const string& key) {
  int index = find_index(key);
  if (index == -1) return "";

  string value = values[index];
  keys[index].clear();
  values[index].clear();

  return value;
}

class DictionaryADT : public MapADT {
public:
  DictionaryADT() : MapADT() {}
  DictionaryADT(string filename);

  void insert(const string& key, const string& value);
  queue<string> find_all(const string& key);
  queue<string> remove(const string& key);
};

void DictionaryADT::insert(const string& key, const string& value) {
  int index = find_index(key, false);
  if (index == -1) {
    cerr << "Table is full!" << endl;
    return;
  }

  keys[index] = key;
  values[index] = value;
}



queue<string> DictionaryADT::remove(const string& key) {
  queue<string> result;
  for (int i = 0; i < size_max; i++)
    if (keys[i] == key) {
      result.push(values[i]);
      keys[i].clear();
      values[i].clear();
    }
  return result;
}

int main() {
  MapADT map;
  map.print();
  map.insert("k1", "v1");
  map.insert("k2", "v2");
  map.print();

  map.insert("k1", "v1b");
  map.print();



  cout << "k2: " << map.remove("k2") << endl;
  map.print();
  cout << "---" << endl;

  DictionaryADT d;
  d.insert("k1", "v1a");
  d.insert("k1", "v1b");
  d.insert("k2", "v2");
  d.print();

  cout << "k1: " << d.find("k1") << endl;
  queue<string> k1v = d.find_all("k1");
  cout << "k1: ";
  while (!k1v.empty()) {
    cout << k1v.front() << ", ";
    k1v.pop();
  }
  cout << endl;
  d.print();

  k1v = d.remove("k1");
  cout << "k1: ";
  while (!k1v.empty()) {
    cout << k1v.front() << ", ";
    k1v.pop();
  }
  cout << endl;
  d.print();

  d.remove("k2");
  d.print();

  return 0;
}
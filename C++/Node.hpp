#ifndef Node_hpp
#define Node_hpp

using namespace std;
// Assume keys and values are the same
// Just maintain keys is enough
template <typename K>
class Node
{
public:
  typedef K Key;
public:
  Node(const K &k = K()) : _key(k) {}
  const K& key() const { return _key; }
  void setKey(const K& k) { _key = k; }
  void printKey() { cout << "Key: " << _key << endl; }
private:
  K _key;
};

#endif // Node_hpp

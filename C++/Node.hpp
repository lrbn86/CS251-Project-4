#ifndef Node_hpp
#define Node_hpp

using namespace std;
// Assume keys and values are the same
template <typename K>
class Node
{
public:
  typedef K Key;
public:
  Node(const K &k = K()) : _key(k) {
    left = NULL;
    right = NULL;
  }
  const K& key() const { return _key; }
  void setKey(const K& k) { _key = k; }
  Node *left;
  Node *right;
  bool hasChildren() {
    if (left == NULL && right == NULL)
    {
      return false;
    }
    return true;
  }
private:
  K _key;
};

#endif // Node_hpp

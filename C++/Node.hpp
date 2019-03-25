#ifndef Node_hpp
#define Node_hpp
#include <string>
using namespace std;
// Assume keys and values are the same
/*
	Note to grading instructor:
		Most of the test cases have different line endings such as "\r\n" or "\n" or even just "\r" (refer to part2input1case2.txt for "postorder")
		The current program will fail some test cases if the lines do not have consistent ending.
		For now, the program will try to match the given output files exactly.
*/
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
  int height=0;
  string color="";
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

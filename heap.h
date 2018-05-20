#include <vector>

class Heap {

private:
  int size;
  std::vector<int> arr;
  
  int root();
  int parent(const int index);
  int get(const int index);
  void set(const int index, const int val);
  bool doExist(const int index);
  bool isLeaf(const int index);
  void swap(const int index1, const int index2);
  int last();
  int leftChild(const int index);
  int rightChild(const int index);
  void fixUp(int index);
  void fixDown(int index);

public:
  Heap ();
  virtual ~Heap ();

  void insert(const int num);
  int deleteMax();
  int getSize();
  void print();
};

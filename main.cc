#include "heap.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  Heap h{};
  h.insert(1);
  h.insert(2);
  h.insert(5);
  h.insert(4);
  std::cout << h << '\n';
  h.deleteMax();
  std::cout << h << '\n';
  return 0;
}

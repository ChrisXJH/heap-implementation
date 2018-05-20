#include "heap.h"
#include <vector>
#include <iostream>

Heap::Heap(): size{0} {};

Heap::~Heap() {};

int Heap::root() {
  return 0;
}

int Heap::parent(const int index) {
  return (index - 1) / 2;
}

int Heap::get(const int index) {
  return arr[index];
}

void Heap::set(const int index, const int val) {
  arr[index] = val;
}

int Heap::getSize() {
  return size;
}

bool Heap::doExist(const int index) {
  return index >= 0 && index <= last();
}

bool Heap::isLeaf(const int index) {
  return !doExist(leftChild(index)) && !doExist(rightChild(index));
}

void Heap::swap(const int index1, const int index2) {
  const int temp = get(index1);
  set(index1, get(index2));
  set(index2, temp);
}

int Heap::last() {
  return size - 1;
}

int Heap::leftChild(const int index) {
  return 2 * index + 1;
}

int Heap::rightChild(const int index) {
  return 2 * index + 2;
}

void Heap::fixUp(int index) {
  while (doExist(parent(index))) {
    const int p = parent(index);
    if (get(index) <= get(p)) break;
    swap(p, index);
    index = p;
  }
}

void Heap::fixDown(int index) {
  while (!isLeaf(index)) {
    int k = leftChild(index);
    int rightIndex = rightChild(index);
    if (doExist(rightIndex) && get(rightIndex) > get(k)) {
      k = rightIndex;
    }

    if (get(k) < get(index)) {
      break;
    }
    else {
      swap(k, index);
      index = k;
    }
  }
}

void Heap::insert(const int num) {
  size++;
  arr.emplace_back(num);
  fixUp(last());
}

int Heap::deleteMax() {
  const int rt = root();
  const int max = get(root());
  swap(rt, last());
  arr.pop_back();
  size--;
  fixDown(rt);
  return max;
}

void Heap::print() {
  bool first = true;
  Heap temp{*this};
  const int size = temp.getSize();
  for (int i = 0; i < size; i++) {
    if (!first) {
      std::cout << ",";
    }
    else {
      first = false;
    }
    std::cout << temp.deleteMax();
  }
  std::cout << '\n';
}

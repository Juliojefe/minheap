#include "minHeap.h"

intMinHeap::intMinHeap(int s) {
  size = 0;
  capacity = s;
  A = new int[capacity];
}

intMinHeap::~intMinHeap() {
  delete[] A;
}

std::pair<int *, int> intMinHeap::heapsort() {
  int temp = size;  // preserve size
  int* sorted_A = new int[size];  //  sorted array
  int* bs = new int[size];  //  holds copy of A
  for (int i = 0; i < temp; ++i) {
    bs[i] = A[i];
  }
  for (int i = size - 1; i >= 0; --i) {
    mySwap(A[0], A[i]);
    --size;
    heapify(0);
  }
  for (int i = 0; i < temp; ++i) {
    sorted_A[i] = A[i];
  }
  for (int i = 0; i < temp; ++i) {
    A[i] = bs[i];
  }
  size = temp;
  delete[] bs;
  return std::make_pair(sorted_A, temp);
}

std::string intMinHeap::toString() {
  std::string str = "heap size " + std::to_string(size) + ": ";
  for (int i = 0; i < size - 1; ++i) {
    str = str + std::to_string(A[i]) + ", ";
  }
  str = str + std::to_string(A[size - 1]);
  return str;
}

bool intMinHeap::heapinsert(int k) {
  if (size >= 0 && size < capacity) {
    ++size;
//    A[size - 1] = k - 1;
    A[size - 1] = k;
    decreasekey(size -1, k);
    return true;
  }
  return false;
}

int intMinHeap::minimum() {
  if (size > 0) {
    return A[0];
  }
  return 0;
}

int intMinHeap::extractmin() {
  if (size > 0) {
    int min = A[0];
    A[0] = A[size -1];
    --size;
    heapify(0);
    return min;
  }
  return 0;
}

void intMinHeap::decreasekey(int i, int k) {
  if (i < size && i >= 0) {
    if (k > A[i]) {return;}
    A[i] = k;
    while (i > 0 && A[parent(i)] > A[i]) {
      mySwap(A[i], A[parent(i)]);
      i = parent(i);
    }
  }
}

bool intMinHeap::isFull() {
  return size == capacity;
}

 int intMinHeap::minOf3(int i, int j, int k) {
  int min = i;
  if (j < size && j >= 0 && A[j] < A[min]) {
    min = j;
  }
  if (k < size && k >= 0 && A[k] < A[min]) {
    min = k;
  }
  return min;
}

int intMinHeap::left(int i) {
  return (i * 2) + 1;
}

int intMinHeap::right(int i) {
  return (i * 2) + 2;
}

int intMinHeap::parent(int i) {
  return (i - 1) / 2;
}

void intMinHeap::buildheap() {
  for (int i = (size / 2) - 1; i >= 0; --i) {
    heapify(i);
  }
}

void intMinHeap::mySwap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void intMinHeap::heapify(int i) {
  int n = minOf3(i, left(i), right(i));
  if (n != i) {
    std::swap(A[i], A[n]);
    heapify(n);
  }
}

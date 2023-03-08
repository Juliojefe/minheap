#ifndef MINHEAP_H
#define MINHEAP_H

#include<string>
// integer minimum heap with PQ 
class intMinHeap{
public:
  intMinHeap(int s);  // empty heap wth this capacity
  ~intMinHeap();  // clean up allocated memory  
  std::pair<int *, int> heapsort();  // return sorted array and size from heap
  std::string toString();  
  bool heapinsert(int k); // add element to heap; return success
  // min functions should return 0 in empty heaps 
  int minimum();  // return value of A[root]
  int extractmin(); // return and remove A[root]
  void decreasekey(int i, int k);  // A[i] decreased to k
  bool isEmpty(){return size == 0;}
  bool isFull(); 
private:
  void mySwap(int& a, int& b);
  int minOf3(int i, int j, int k); // with bounds check!
  int left(int i);
  int right(int i);
  int parent(int i);	
  void buildheap();  // convert array to a heap
  void heapify(int i);  // heapify at position i  
  int *A;  // array of integers - data
  int capacity; // size of array A
  int size; // data size in array
 };

#endif
/*
Julio Fernandez
jfernand@pengo.cabrillo.edu
Preferred email - j.c.jf285@gmail.com
main.cpp
Assignment 2 (inMinHeap)

Here I create an intMinHeap object with a capacity of 2,400,000.
My data structure always stores its internal data as a binary heap.

My main function reads in all input from STDIN until EOF.
Each line will consist of a single integer.

If the input value is a positive integer it is inserted into my object.
This operation prints "insert" and the value that was added,
unless it is full.

If the input value is zero the heap and the size of the heap are printed
on a single line of text as a comma-separated list.

If the input value is -1 the minimum value is extracted from my
object and printed on a single line.

If the input value is -2 I call heapsort, and then print,
on a single line, as a comma-separated list the sorted array
returned from heapsort.

Code status: tested/working and compiles
*/

#include <iostream>
#include "intMinHeap.h"

int main() {
  int s;
  intMinHeap minHeap(2400000);
  while (std::cin >> s) {
    if (s > 0 && s != -2 && s != -1 && s != 0) {
      if (minHeap.heapinsert(s)) {
        std::cout << "insert: " << s << '\n';
      }
      else {
        std::cout << "no insert object is full\n";
      }
    }
    if (s == 0) {
      std::cout << minHeap.toString() << '\n';
    }
    if (s == -1) {
      std::cout << "extract min: " << minHeap.extractmin() << '\n';
    }
    if (s == -2) {
      auto sorted = minHeap.heapsort();
      if (sorted.second == 0) {
        std::cout << "sorted array: []\n";
      }
      if (sorted.second > 0) {
        std::cout << "sorted array: [";
        for (int i = 0; i < sorted.second - 1; ++i) {
          std::cout << sorted.first[i] << ", ";
        }
        std::cout << sorted.first[sorted.second - 1] << "]\n";
      }
      delete[] sorted.first;
    }
  }
}
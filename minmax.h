#ifndef MINMAX_H
#define MINMAX_H

using namespace std;

class minmax {
public:
  minmax();
  ~minmax();
  void insert(int val);
  void buildHeap();
  void grandparentSwap();
  void removeRoot();
  void printMin();
  void printMax();
  void print();

private:
  int size;
  int* heap;

};
#endif

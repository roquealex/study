/*
 * Heap.h
 *
 *  Created on: Nov 11, 2018
 *      Author: roquealex
 */

#ifndef HEAP_H_
#define HEAP_H_

#include "HeapBase.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

template <class T>
class Heap : public HeapBase {
private:
  std::vector<T>& _v;
  size_t _getH() const;

  bool _compIndex(size_t, size_t);
  void _swapIndex(size_t, size_t);

public:
  Heap(std::vector<T> &v) : _v(v) {};
  void printHeap() const;

  size_t getSize() const;
  /**
   * Adds a new element to the heap. Since this heap is based on
   * a vector it will grow after the execution of this method.
   * The heap properties are kept
   * @param t New element to be added.
   * @see popHeap()
   */
  void pushHeap(const T& t);
  /**
   * Returns a reference the front element from the heap.
   * The element won't be removed.
   * @see popHeap()
   */
  T& frontHeap() const;
  /**
   * Removes the front element from the heap. It doesn;t return the
   * element so a call to frontHeap if we want to keep it.
   * @see frontHeap()
   */
  void popHeap();

};

template <class T>
size_t Heap<T>::_getH() const {
  size_t h = 0;
  auto size = getSize();
  while(size) {
    h++;
    size>>=1;
  }
  return h;
}

template <class T>
bool Heap<T>::_compIndex(size_t i, size_t j) {
  return (_v[i] > _v[j]);
}
template <class T>
void Heap<T>::_swapIndex(size_t i, size_t j) {
  std::swap(_v[i],_v[j]);
}

template <class T>
size_t Heap<T>::getSize() const {
  return _v.size();
}

template <class T>
void Heap<T>::pushHeap(const T& t) {
  _v.push_back(t);
  heapifyUp(getSize()-1);
}

template <class T>
T& Heap<T>::frontHeap() const {
  return _v[0];
}

template <class T>
void Heap<T>::popHeap() {
  size_t size = getSize();
  size--;
  std::swap(_v[0],_v[size]);
  _v.pop_back();
  maxHeapify(0,size);
}

template <class T>
void Heap<T>::printHeap() const {
  using namespace std;
  unsigned int lim = 2;
  size_t h = _getH();
  int w = (1<<(h-1))*4;
  for(unsigned int i = 0 ; i < getSize() ; i++) {
    if (lim == i+1) {
      cout<<endl;
      lim<<=1;
      w >>=1;
    }
    cout<<left<<setw(w)<<_v[i];
  }
  cout<<endl;

}

#endif /* HEAP_H_ */

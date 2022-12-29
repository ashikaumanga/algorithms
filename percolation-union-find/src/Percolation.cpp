#include <iostream>
#include "Percolation.h"



Percolation::Percolation(int size) {
  
  grid.reset(new vector<bool>(size*size));
  //qunion should have (size*size) + 2 elements
  // 0 : top virtual node
  // (size*size) + 1 : bottom virtual node

  qunion.reset(new QuickUnion(size*size + 2));
  this->size = size;
  for (int i=0; i< size*size; i++) {
    grid->at(i) = false;
  }
  this->virtual_bottom_index = size * size + 1;
  //link top element to virtual top node
  for (int i=0; i<size; i++) {
        qunion->connect(virtual_top_index, i+1);
  }
  //link bottom  row element to virtual bottom node
  for (int i=(size -1)* size, j=0; j < size; j++) {
        int ind = (i + j) + 1;
        qunion->connect(virtual_bottom_index, ind);
  }
  
}

void Percolation::open(int row, int col) {
    grid->at(row*size + col) = true;
    openSites++;
}

bool Percolation::isOpen(int row, int col) {
  return grid->at(row*size + col);
}
bool Percolation::isFull(int row, int col) {
  return qunion->isConnected(virtual_top_index, virtual_bottom_index);
}
int Percolation::numberOfOpenSites() {
    return openSites;
}

bool Percolation::percolates() {
    return qunion->isConnected(virtual_top_index, virtual_bottom_index);
}
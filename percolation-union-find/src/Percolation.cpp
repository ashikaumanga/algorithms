#include <iostream>
#include "Percolation.h"

bool validRange(int size, int row, int col) {
  if (row < 0) return false;
  if (row >= size) return false;
  if (col < 0) return false;
  if (col >= size) return false;
  return true;

}


Percolation::Percolation(int size) {
  
  grid.reset(new vector<bool>(size*size));
  //qunion should have (size*size) + 2 elements
  // 0 : top virtual node
  // (size*size) + 1 : bottom virtual node

  qunion.reset(new QuickUnion((size*size) + 2));
  this->size = size;
  for (int i=0; i< size*size; i++) {
    grid->at(i) = false;
  }
  this->virtual_bottom_index = size * size + 1;
  //link top,bottom element to virtual top node/bottom node
  for (int i=0; i<size; i++) {
        //link top row elements to virtual top
        qunion->connect(virtual_top_index, i+1);
        //link bottom row elements to virtual bottom
        int q = getUnionIndex(size -1, i);
        qunion->connect(virtual_bottom_index, q);
  }
  //link bottom  row element to virtual bottom node
  //for (int i=(size -1)* size, j=0; j < size; j++) {
  //      int ind = (i + j) + 1;
  //      qunion->connect(virtual_bottom_index, ind);
 // }
  
}

 int Percolation::getUnionIndex(int row, int col) {
    return (this->size * row + col)+1;
 }

 int Percolation::gridSize() {
    return this->size;
 }

void Percolation::open(int row, int col) {
    if(!validRange(this->size,row,col)) return;
    int ind = row*size + col;
    grid->at(ind) = true;
    //create the connections in the union data-structure
    //left
    if (validRange(this->size,row-1,col) && isOpen(row-1,col)) {
        int unionP = getUnionIndex(row,col);
        int unionQ = getUnionIndex(row-1,col);
        qunion->connect(unionP, unionQ);
    }
    //right
    if (validRange(this->size,row+1,col) && isOpen(row+1,col)) {
        int unionP = getUnionIndex(row,col);
        int unionQ = getUnionIndex(row+1,col);
        qunion->connect(unionP, unionQ);
    }
    //top
    if (validRange(this->size,row,col-1) && isOpen(row,col-1)) {
        int unionP = getUnionIndex(row,col);
        int unionQ = getUnionIndex(row,col-1);
        qunion->connect(unionP, unionQ);
    }
    //bottom
    if (validRange(this->size,row,col+1) && isOpen(row,col+1)) {
        int unionP = getUnionIndex(row,col);
        int unionQ = getUnionIndex(row,col+1);
        qunion->connect(unionP, unionQ);
    }
    openSites++;
}

bool Percolation::isOpen(int row, int col) {
  return grid->at(row*size + col);
}
bool Percolation::isFull(int row, int col) {
  return (validRange(this->size,row,col) && isOpen(row,col)) &&
  ((validRange(this->size,row,col) && isOpen(row,col) && qunion->isConnected(virtual_top_index, getUnionIndex(row,col))) ||
  (validRange(this->size,row-1,col) && isOpen(row-1,col) && qunion->isConnected(virtual_top_index, getUnionIndex(row-1,col))) ||
  (validRange(this->size,row+1,col) && isOpen(row+1,col) && qunion->isConnected(virtual_top_index, getUnionIndex(row+1,col))) ||
  (validRange(this->size,row,col-1) && isOpen(row,col-1) && qunion->isConnected(virtual_top_index, getUnionIndex(row,col-1))) ||
   (validRange(this->size,row,col+1) && isOpen(row,col+1) && qunion->isConnected(virtual_top_index, getUnionIndex(row,col+1)))); 

}
int Percolation::numberOfOpenSites() {
    return openSites;
}

bool Percolation::percolates() {
    return qunion->isConnected(virtual_top_index, virtual_bottom_index);
}
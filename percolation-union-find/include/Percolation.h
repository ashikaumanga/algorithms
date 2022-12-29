#ifndef H_PERC
#define H_PERC

#include <vector>
#include "QuickUnion.h"

using namespace std;

class Percolation {
  private:
   unique_ptr<QuickUnion> qunion = nullptr;
   unique_ptr<vector<bool>> grid = nullptr;
   int virtual_top_index = 0;
   int virtual_bottom_index = INT_MAX;

   // [r0c0,r0c1,...r0c-size-1],[r1c0r1c1,.... r1c-size-1]
   int size; //grid size (size x size)
   int openSites = 0;
   
  public:
   Percolation(int size);

   void open(int row,int col);
   bool isOpen(int row, int col);
   bool isFull(int row, int col);
   int numberOfOpenSites();

   bool percolates();

};

#endif
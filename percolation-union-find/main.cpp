#include <iostream>
#include "include/Percolation.h"
#include "include/QuickUnion.h"

int main(int, char**) {
    std::cout << "Hello, world!\n";

    //Percolation p(40);
    //std::cout << p.isFull(1,1) ;
    QuickUnion un(8);

   
    un.connect(0,1);
     std::cout << "(3,4)" << un.isConnected(3,4) << std::endl ;
    un.connect(1,3);
     std::cout << "(3,4)" << un.isConnected(3,4) << std::endl ;
     un.connect(4,1);
    std::cout << "(3,4)" << un.isConnected(3,4) << std::endl ;
    std::cout << "(1,7)" << un.isConnected(1,7) << std::endl ;
    un.connect(5,6);
    std::cout << "(1,7)" << un.isConnected(1,7) << std::endl ;
     un.connect(5,7);
     std::cout << "(1,7)" << un.isConnected(1,7) << std::endl ;
      un.connect(4,7);
      std::cout << "(1,7)" << un.isConnected(1,7) << std::endl ;

      Percolation p(40);

      std::cout << "isOpen(0,13)" << p.isOpen(0,13) << std::endl ;
      p.open(0,13);
      std::cout << "isOpen(0,13)" << p.isOpen(0,13) << std::endl ;
      std::cout << "isOpen(35,10)" << p.isOpen(35,10) << std::endl ;
      p.open(35,10);
      std::cout << "isOpen(35,10)" << p.isOpen(35,10) << std::endl ;



    
}

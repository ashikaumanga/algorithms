#ifndef H_QUICKUNION
#define H_QUICKUNION

#include <vector>

using namespace std;

class QuickUnion {
   private:
     unique_ptr<vector<int>> arr = nullptr;
     int rootOf(int p);

   public:
    QuickUnion(int size);
    void connect(int p, int q);
    bool isConnected(int p,int q);

};

#endif
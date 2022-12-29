#include "QuickUnion.h"

    int QuickUnion::rootOf(int p) {
        int tmp = arr->at(p);
        while (tmp != arr->at(tmp)) {
            tmp = arr->at(tmp);
        }
        return tmp;
    }

    QuickUnion::QuickUnion(int size) {
        this->arr.reset(new vector<int>(size));
        for (int i=0;i < size; i++) {
            arr->at(i) = i;
        }
    }
    
    void QuickUnion::connect(int p, int q) {
        int rootP = rootOf(p);
        int rootQ = rootOf(q);
        arr->at(rootQ) = arr->at(rootP);
    }
    bool QuickUnion::isConnected(int p,int q) {
        return rootOf(p) == rootOf(q);
    }

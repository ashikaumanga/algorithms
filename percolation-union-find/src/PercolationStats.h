#ifndef H_PERCOLATION_SET
#define H_PERCOLATION_SET

class PercolationStats {
  public:
    PercolationStats(int n, int trials);
    double mean();
    double stddev();
    double confidenceLo();
    double confidenceHi();
   
};

#endif
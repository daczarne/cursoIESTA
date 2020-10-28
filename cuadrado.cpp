#include <Rcpp.h>
using namespace Rcpp;

inline double square(double x) { return x*x ; }

// [[Rcpp::export]]
std::vector<double> transformEx(const std::vector<double>& x) {
  std::vector<double> y(x.size());
  std::transform(x.begin(), x.end(), y.begin(), square);
  return y;
}


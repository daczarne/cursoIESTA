// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h> 
using namespace Rcpp;
using namespace arma;
// [[Rcpp::export]]
List fastLm(const arma::mat& X, const arma::colvec& y) { int n = X.n_rows, k = X.n_cols;
  colvec coef = solve(X, y); colvec resid = y - X*coef;
  double sig2 = as_scalar(trans(resid)*resid/(n-k));
  colvec stderrest = sqrt(sig2 * diagvec( inv(trans(X)*X)) );
  return List::create(Named("coefficients") = coef, Named("stderr") = stderrest, Named("df.residual") = n - k );
}
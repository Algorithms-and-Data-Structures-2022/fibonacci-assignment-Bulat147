#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }
    int five = 5;
    double frst_numer = std::pow((1 + std::sqrt(five))/2, n);
    double scnd_numer = std::pow((1 - std::sqrt(five))/2, n);
    double denom = std::sqrt(five);
    int64_t ret = std::round((frst_numer-scnd_numer)/denom);
    return ret;
  }

  int64_t fib_iterative(int n) {
    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;
    int64_t temp;
    for (int i = 0; i<n;i++){
      temp = fib_prev;
      fib_prev = fib_curr;
      fib_curr += temp;
    }
    return fib_prev;
  }

  int64_t fib_recursive(int n) {
    if (n <= 1){
      return n;
    }
    int64_t ret = fib_recursive(n-1) + fib_recursive(n-2);
    return ret;
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      return cache[n];
    }

    cache[n] = fib_recursive_memoization(n-1, cache) + fib_recursive_memoization(n-2, cache);

    return cache[n];
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    Matrix2x2 matr;
    matr[0][0] = 1;
    matr[0][1] = 1;
    matr[1][0] = 1;
    matr[1][1] = 0;
    matr = matrix_power(matr, n);
    // Tip: используйте реализованную функцию matrix_pow

    return matr[0][1];
  }

}  // namespace assignment

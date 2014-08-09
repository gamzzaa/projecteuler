// Project Euler
// -------------
//
// Problem 2. Even Fibonacci numbers
//
// By considering the terms in the Fibonacci sequence whose values
// do not exceed four million, find the sum of the even-valued terms.
//
// File: EvenFibonacciNumbers.cpp

#include <iostream>
#include "FibonacciGenerator.hpp"

using namespace std;

const long maxValue = 4000000L;

int main() {
  int sum = 0;
  int evenTerm = 0;
  FibonacciGenerator fg(1L,2L);

  while ((evenTerm = fg.nextEvenTerm()) < maxValue) {
    sum += evenTerm;
  }

  cout << "Sum: " << sum << endl;

  return 0;
}

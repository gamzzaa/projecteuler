// Project Euler
// -------------
//
// Problem 2. Even Fibonacci numbers
//
// By considering the terms in the Fibonacci sequence whose values
// do not exceed four million, find the sum of the even-valued terms.
//
// File: FibonacciGenerator.cpp

#include <iostream>
#include "FibonacciGenerator.hpp"


long FibonacciGenerator::next() {
  long sum;
  sum = firstTerm + secondTerm;

  firstTerm = secondTerm;
  secondTerm = sum;

  return sum;
}

long FibonacciGenerator::nextEvenTerm() {
  long sum = -1;

  while (sum%2 != 0) {
    sum = firstTerm + secondTerm;
    firstTerm = secondTerm;
    secondTerm = sum;
  }

  return sum;
}

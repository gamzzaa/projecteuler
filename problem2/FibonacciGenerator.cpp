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
  long evenTerm = 0;
  bool running = true;

  while (running) {
    if (isEven(firstTerm)) {
      evenTerm = firstTerm;
      running = false;
    } else if (isEven(secondTerm)) {
      evenTerm = secondTerm;
      running = false;
    } else {
      nextTwoTerms();
    }
  }

  nextTwoTerms();

  return evenTerm;
}

bool FibonacciGenerator::isEven(long term) {
  return term%2 == 0;
}

void FibonacciGenerator::nextTwoTerms() {
  // There are two terms

  // firstTerm    secondTerm
  //     |            |
  //     v            v
  //     1            2            3            5

  // After invoking next() method two times there is following situation:

  //                           firstTerm    secondTerm
  //                               |            |
  //                               v            v
  //     1            2            3            5

  next();
  next();
}

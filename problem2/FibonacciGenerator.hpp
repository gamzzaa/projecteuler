// Project Euler
// -------------
//
// Problem 2. Even Fibonacci numbers
//
// By considering the terms in the Fibonacci sequence whose values
// do not exceed four million, find the sum of the even-valued terms.
//
// File: FibonacciGenerator.hpp

#ifndef FIBONACCI_GENERATOR_H
#define FIBONACCI_GENERATOR_H

class FibonacciGenerator {
  public:
    FibonacciGenerator(long termA, long termB) {
      firstTerm = termA;
      secondTerm = termB;
    }

    long next();
    long nextEvenTerm();

  private:
    long firstTerm;
    long secondTerm;
};

#endif // FIBONACCI_GENERATOR_H

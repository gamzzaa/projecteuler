// Project Euler
// -------------
//
// Problem 1. Multiples of 3 and 5
//
// Find the sum of all the multiples of 3 or 5 below 1000.
//
// File: Multiples3_5.cpp

#include <iostream>

using namespace std;

const int maxNumber = 1000;

int main() {
  int sum = 0;

  for (int i = 1; i < maxNumber; i++) {
    if (i%3 == 0 || i%5 == 0) {
      sum += i;
    }
  }

  cout << "Sum: " << sum << endl;

  return 0;
}

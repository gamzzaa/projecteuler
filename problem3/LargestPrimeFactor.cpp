// Project Euler
// -------------
//
// Problem 3. Largest prime factor
//
// What is the largest prime factor of the number 600851475143?
//
// File: LargestPrimeFactor.cpp

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const long long number = 600851475143L;

std::vector<bool> prime_sieve(const long long& n) {
  std::vector<bool> numbers;

  numbers.push_back(false);
  numbers.push_back(false);

  for (long long i = 2; i <= n; i++) {
    numbers.push_back(true);
  }

  for (long long i = 2; i <= n; i++) {
    if (numbers.at(i)) {
      for (long long j = i*i; j <= n; j+=i) {
        numbers.at(j) = false;
      }
    }
  }

  return numbers;
} // end of function

std::vector<long long> prime_sieve_comp(std::vector<bool>& vNumbers) {
  std::vector<long long> vPrimeNumbers;

  for (long long i = 0; i < vNumbers.size(); i++) {
    if (vNumbers.at(i)) vPrimeNumbers.push_back(i);
  }

  return vPrimeNumbers;
}

std::vector<long long> trial_division(const long long& n) {
  std::vector<long long> pfactors;

  if (n == 1) {
    pfactors.push_back(n);
    return pfactors;
  }

  long product = int(sqrt(n)) + 1;

  std::vector<bool> vPrimePattern = prime_sieve(product);
  std::vector<long long> vPrimeNums = prime_sieve_comp(vPrimePattern);

  long long nTemp = n;
  for (std::vector<long long>::iterator prime = vPrimeNums.begin(); prime != vPrimeNums.end(); prime++) {
    if (*prime * (*prime) > nTemp) break;

    while (nTemp % (*prime) == 0) {
      pfactors.push_back(*prime);
      nTemp /= *prime;
    }
  }

  if (nTemp > 1) pfactors.push_back(nTemp);

  return pfactors;
}

int main() {
  std::vector<long long> vPrimeFactors = trial_division(number);

  for (std::vector<long long>::iterator it = vPrimeFactors.begin(); it != vPrimeFactors.end(); it++) {
    std::cout << *it << std::endl;
  }

  return 0;
}

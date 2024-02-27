#include <iostream>

using namespace std;

// c++ 14
constexpr bool isPrime(unsigned p) {
  for (unsigned d = 2; d <= p / 2; ++d) {
    if (p % d == 0)
      return false;
  }
  return p > 1;
}

template <int SZ, bool = isPrime(SZ)> struct Helper0;

template <int SZ> struct Helper0<SZ, false> {
  Helper0() { cout << SZ << " is not a prime." << endl; }
};

template <int SZ> struct Helper0<SZ, true> {
  Helper0() { cout << SZ << " is a prime." << endl; }
};

template <int SZ, bool = isPrime(SZ)> struct Helper1 {
  Helper1() { cout << SZ << " is not a prime." << endl; }
};

template <int SZ> struct Helper1<SZ, true> {
  Helper1() { cout << SZ << " is a prime." << endl; }
};

int main(int argc, char *argv[]) {
  Helper0<2> b;
  Helper0<9> a;
  Helper1<2> c;
  Helper1<9> d;
  return 0;
}

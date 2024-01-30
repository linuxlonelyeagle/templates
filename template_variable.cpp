#include <array>
#include <iostream>

// since c++ 14
template <int N> std::array<int, N> arr{}; // zero-initialized
template <auto N> decltype(N) dval = N;

int main() {
  std::cout << dval<'c'> << std::endl;
  for (int i = 0; i != 10; ++i)
    arr<10>[i] = i;
  for (int i = 0; i != 10; ++i)
    std::cout << arr<10>[i] << std::endl;
  return 0;
}
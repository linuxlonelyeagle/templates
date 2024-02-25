#include <iostream>

using namespace std;

template <unsigned p, unsigned d> struct DoIsPrime {
  static constexpr bool value = (p % d != 0) && DoIsPrime<p, d - 1>::value;
};

template <unsigned p> struct DoIsPrime<p, 2> {
  static constexpr bool value = (p % 2 != 0);
};

template <unsigned p> struct IsPrime {
  static constexpr bool value = DoIsPrime<p, p / 2>::value;
};

template <> struct IsPrime<0> {
  static constexpr bool value = false;
};

template <> struct IsPrime<1> {
  static constexpr bool value = false;
};

template <> struct IsPrime<2> {
  static constexpr bool value = true;
};

template <> struct IsPrime<3> {
  static constexpr bool value = true;
};

// c++ 11
constexpr bool doIsPrime(unsigned p, unsigned d) {
  return d != 2 ? (p % d != 0) && doIsPrime(p, d - 1) : (p % 2 != 0);
}

constexpr bool isPrime0(unsigned p) {
  return p < 4 ? !(p < 2) : doIsPrime(p, p / 2);
}

constexpr bool isPrime1(unsigned p) {
  for (unsigned d = 2; d <= p / 2; ++d) {
    if (p % d == 0)
      return false;
  }
  return p > 1;
}

// 全局作用域，或 namespace 在编译期间执行
constexpr bool b1 = isPrime1(9);

// 是否进行编译期计算是由编译期决定
bool fiftySevenIsPrime() { return isPrime1(57); }

int main(int argc, char *argv[]) {
  // IsPrime<9> -> DoIsPrime<9, 4> -> DoIsPrime<9, 3> -> DoIsPrime<9, 2>
  cout << IsPrime<9>::value << endl;

  // 编译器在编译期对被调用的 constexpr 函数进行计算。
  // 此时如果无法在编译器进行计算，就会报错，如果这个时候
  // 需要产生一个值。
  // 在其它的上下文中，编译器可能会可能不会尝试编译期计算。
  // 如果尝试了，但是现在条件不满足编译期计算的要求。那么相应的
  // 函数调用会被推迟到运行期间执行。

  // 调用只会在运行期间执行。
  int x;
  std::cout << isPrime1(x) << endl;
  return 0;
}

#include <iostream>

using namespace std;

template <typename T> class Base {
public:
  void bar() { cout << "bar." << endl; }
};

template <typename T> class Derived : Base<T> {
public:
  void foo() {
    this->bar();
    Base<T>::bar();
  };
};

int main() {
  Derived<int> a;
  a.foo();
  return 0;
}

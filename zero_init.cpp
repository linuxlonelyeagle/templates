#include <iostream>

using namespace std;

template<typename T>
void print() {
  T value {};
  cout << value << endl;
}

template<typename T>
class MyClass {
  T data;
  public:
  MyClass() : data {} {
    cout << data << endl;
  }

};

int main() {
  print<int>();
  print<bool>();
  MyClass<int> a;
  MyClass<double> b;
  return 0;
}

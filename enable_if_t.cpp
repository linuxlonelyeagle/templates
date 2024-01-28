#include <unordered_set>
#include <iostream>
#include <string> 
using namespace std;

template<typename T>
std::enable_if_t<std::is_same_v<T, int>> print0(T value) {
  cout << "int version." << endl;
  cout << value << endl;  
}

template<typename T> 
std::enable_if_t<std::is_same_v<T, double>> print0(T value) {
  cout << "double version." << endl;
  cout << value <<endl;
}

template<typename T, std::enable_if_t<std::is_same_v<T, int>, int> int1 = 10>
void print1(T int0) {
  cout << "int and int" << endl;
  cout << int0 << " " << int1 << endl;
  return;
}

template<typename T, std::enable_if_t<std::is_same_v<T, size_t>, size_t> size1 = 10>
void print1(T size0) {
  cout << "size and size" << endl;
  cout << size0 << " " << size1 << endl;
  return;
};

template<typename T, typename U>
class A {
  U data1;
  public:
  void print() {
    cout << "normal version." << endl;
  }
};

template<typename T>
class A<T, std::enable_if_t<std::is_same_v<T, int>>> {
  public:
  void print() {
    cout << "int version." << endl;
  }
};


int main() {
  print0(2);
  print0(2.0);
  print1(static_cast<int>(10));
  print1(static_cast<size_t>(10));
  A a(static_cast<int>(0));
  a.print();
  return 0;
}
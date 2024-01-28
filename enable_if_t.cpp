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

template<typename T, typename Tag = int>
class A {
  T data0;
  Tag data1;
  public:
    A() = default;
    A(T data0, Tag data1) : data0 {data0}, data1 {data1} { }
    void print() {
      cout << "normal version." << endl;
      cout << "data0:" << data0 << endl;
      cout << "data1:" << data1 << endl; 
    }
};

template<typename T>
class A<T, std::enable_if_t<std::is_same_v<T, std::string>, std::string>> {
  T data0; 
  using Tag = std::enable_if_t<std::is_same_v<T, std::string>, std::string>;
  Tag data1;
  public:
     A() = default;
     A(T data0, Tag data1) : data0 {data0}, data1 {data1} { }
     void print() {
      cout << "std::string version." << endl;
      cout << "data0:" << data0 << endl;
      cout << "data1:" << data1 << endl;
     }
};

int main() {
  print0(2);
  print0(2.0);
  print1(static_cast<int>(10));
  print1(static_cast<size_t>(10));
  A a0(10, 10);
  a0.print();
  A a1(std::string("hello"), std::string("world"));
  a1.print();
  return 0;
}

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


int main() {
  print0(2);
  print0(2.0);
  print1(static_cast<int>(10));
  print1(static_cast<size_t>(10));
  return 0;
}
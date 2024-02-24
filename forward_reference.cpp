#include <iostream>

using namespace std;

template <typename T>
void passR (T&& arg) {
  // T x;
  // passR(42); ok T is int
  // int i; passR(i); T is int&
}

int main(int argc, char* argv[]) {
  string s = "hi";
  passR(s); // string&
  passR(string("hi")); // string&&
  passR(move(s)); // string&&
  char arr[3];
  passR(arr); // char (&)[3]
  string const c = "hi";
  passR(c); // const string&
  passR("hi"); // const char (&)[3]
  return 0;
}

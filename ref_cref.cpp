#include <functional>
#include <iostream>

using namespace std;
void printString(string const &s) { cout << s << endl; }

template <typename T> void printT(T arg) { printString(arg); }

int main(int argc, char *argv[]) {
  string s = "hello";
  printT(s);

  // 他用一个行为和引用类似的对象对参数进行了封装
  // 实际上，创建了一个std::reference_wrapper<>
  // 对象，该对象引用了原始参数，并被按值传递给了函数
  // 模版
  // std::reference_warpper<>可能只支持一个操作
  // 向原始类型的隐式类型转换，该转换返回原始参数对象
  printT(ref(s));
  printT(cref(s));
  return 0;
}

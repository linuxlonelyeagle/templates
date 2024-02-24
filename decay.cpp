#include <iostream>

template <typename T> void print(T arg) {}

// 这个模版永远不会拷贝被传递的对象
// 按照引用传递可能并不能提高性能，因为
// 底层的实现上，按引用传递还是通过传递
// 参数的地址实现的，理论上调用者可以随意
// 更改地址指向的内容，这样编译器就要假设
// 在这次调用之后，所有缓存在寄存器中的值
// 可能都会变为无效。而重新载入这些变量的
// 值可能会很耗时。
// 按照引用传递参数时，其类型不会退化，也就是
// 说不会把裸数组转化为指针，也不会移除const
// 和 volatile 等限制符
template <typename T> void printR(T const &arg) {}

template <typename T /*, typename = std::enable_if_t<!std::is_const_v<T>>*/>
void outR(T &arg) {
  if (std::is_array_v<T>) {
    // 如果是数组类型，获取数组的长度。
    std::cout << "got array of " << std::extent_v<T> << " elems\n";
  }
}

int main(int argc, char *argv[]) {
  // 就像用一个值去初始化用auto声明的对象那样。
  int a = 0;
  print(a); // int
  int const b = 0;
  print(b); // int
  int const volatile c = 0;
  print(c); // int
  std::string const d{"hi"};
  print(d); // std::string
  int arr[4];
  print(arr);  // int*
  print("hi"); // const char*

  printR(d);                 // const std::string&
  printR(std::string("hi")); // const std::string&
  std::string tmp("hi");
  printR(std::move(tmp)); // const std::string&
  printR(a);              // const int&

  outR(d);   // string&
  outR(arr); // int [4]
  std::string const e{"hi"};
  outR(e);            // const string&
  outR(std::move(d)); // const string&
  outR("hi");         // const char& [3]
  return 0;
}

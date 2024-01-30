#include <iostream>
#include <string>

template <typename T>
using EnableIfString = std::enable_if_t<std::is_convertible_v<T, std::string>>;

class Person {
private:
  std::string name;

public:
  template <typename STR, typename = EnableIfString<STR>>
  explicit Person(STR &&n) : name(std::forward<STR>(n)) {
    std::cout << "TMPL-CONSTR for '" << name << "'\n";
  }
  Person(Person const &p) : name(p.name) {
    std::cout << "COPY-CONSTR Person '" << name << "'\n";
  }
  Person(Person &&p) : name(std::move(p.name)) {
    std::cout << "MOVE-CONSTR Person '" << name << "'\n";
  }
};

int main() {
  std::string s = "name";
  // infer char const[4];
  Person p1(s);
  Person p2("tmp");
  // If EnableIfString is not used, will match to explicit Person(STR&& n).
  Person p3(p1);
  Person p4(std::move(p1));
  return 0;
}
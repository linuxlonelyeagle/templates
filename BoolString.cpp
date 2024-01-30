#include <iostream>
#include <string>
using namespace std;
class BoolString {
private:
  std::string value;

public:
  BoolString(std::string const &s) : value{s} {}
  template <typename T = std::string> T get() const { return value; }
};

template <> inline bool BoolString::get<bool>() const {
  return value == "true" || value == "1" || value == "on";
}

int main() {
  BoolString s0("true");
  cout << s0.get<string>() << endl;
  cout << s0.get<bool>() << endl;
  BoolString s1("false");
  cout << s1.get<string>() << endl;
  cout << s1.get<bool>() << endl;
  return 0;
}
#include <cassert>
#include <deque>
#include <iostream>
#include <memory>

using namespace std;

template <typename T, template <typename Elem, typename = std::allocator<Elem>>
                      class Cont = std::deque>
class Stack {
  template <typename, template <typename, typename> class> friend class Stack;

private:
  Cont<T> elems;

public:
  void push(T const &);
  void pop();
  T const &top() const;
  bool empty() const { return elems.empty(); }
  template <typename T2,
            template <typename Elem, typename = std::allocator<Elem>>
            class Cont2 = std::deque>
  Stack<T, Cont> &operator=(Stack<T2, Cont2> const &);
};

template <typename T, template <typename, typename> class Cont>
void Stack<T, Cont>::push(T const &elem) {
  elems.push_back(elem);
}

template <typename T, template <typename, typename> class Cont>
void Stack<T, Cont>::pop() {
  assert(!elems.empty());
  elems.pop_back();
}

template <typename T, template <typename, typename> class Cont>
T const &Stack<T, Cont>::top() const {
  assert(!elems.empty());
  return elems.back();
}

template <typename T, template <typename, typename> class Cont>
template <typename T2, template <typename, typename> class Cont2>
Stack<T, Cont> &Stack<T, Cont>::operator=(Stack<T2, Cont2> const &op2) {
  elems.clear();
  elems.insert(elems.begin(), op2.elems.begin(), op2.elems.end());
  return *this;
}

int main() {
  Stack<int> iStack;
  Stack<float> fStack;
  iStack.push(1);
  iStack.push(2);
  iStack.push(3);
  fStack = iStack;
  while (!fStack.empty()) {
    cout << fStack.top() << endl;
    fStack.pop();
  }
  return 0;
}
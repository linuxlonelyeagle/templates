#include <iostream>
#include <deque>

using namespace std;

template<typename T>
class Stack {
  // use friend to make Stack be friend class.
  template<typename> friend class Stack;
  private:
    std::deque<T> elems;
  public:
    void push(T const& value) {
      elems.push_back(value);
    }
    void pop() {
      assert(!elems.empty());
      elems.pop_back();
    }

    T const& top() const {
      return elems.back();
    }

    bool empty() const {
      return elems.empty();
    } 
    template<typename T2>
    Stack& operator=(Stack<T2> const&);  
};

template<typename T>
template<typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& op2) {
  elems.clear();
  elems.insert(elems.begin(), 
  op2.elems.begin(), op2.elems.end());
  return *this;
}

int main() {
  Stack<float> floatStack;
  floatStack.push(0);
  floatStack.push(1);
  Stack<int> intStack;
  intStack = floatStack;
  cout << intStack.top() << endl;
  intStack.pop();
  cout << intStack.top() << endl;
  intStack.pop();
  return 0;
}

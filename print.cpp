#include <utility>
#include <iostream>

using namespace std;

// define print function.
template<typename T>
void print(T arg) {
    std::cout << arg << std::endl;
}

template<typename T, typename... Types>
void print(T firstArgs, Types... args) {
    std::cout << firstArgs << std::endl;
    print(args...);
}

template<typename... Types>
void printDoubled (Types const&... args) {
    print(args + args ...);
}

template<typename... Types>
void addOne (Types const&... args) {
    print(1 + args ...);
}

template<typename C, typename... Idx>
void printElems (C const& coll, Idx... idx) {
    print(coll[idx]...);
}

template<size_t... Idx, typename C> 
void printIdx(C const& coll) {
    print(coll[Idx]...);
}

template<std::size_t...>
struct Indices {

};

template<typename T, std::size_t... Idx>
void printByIdx(T t, Indices<Idx...>) {
    print(std::get<Idx>(t)...);
}

int main() {
    std::cout << "test print." << std::endl;
    print(1 , 2, 3, "hello", "world");
    std::cout << "test printDoubled." << std::endl;
    printDoubled(1, 2, 3);
    std::cout << "test addOne." << std::endl;
    addOne(1, 2, 3);
    std::cout << "test printElems." << std::endl;
    vector<int> vec {1, 2, 3, 4};
    printElems(vec, 3, 2, 1, 0);
    std::cout << "test printIdx." << std::endl;
    printIdx<3, 2, 1, 0>(vec);
    std::cout << "test printByIdx" << std::endl;
    std::array<std::string, 5> arr {"Hello", "my", "new", "!", "world"};
    printByIdx(arr, Indices<0, 4, 3>());
    return 0;
}

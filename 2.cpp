#include <iostream>
#include <vector>

using namespace std;

class A {
 public:
    int v = 0;
    A() {
        std::cout << "A()." << std::endl;
    }
    A(const A& other) {
        std::cout << "A(&)." << std::endl;
    }
    A(A&& o) noexcept : v(std::move(o.v)) {
        std::cout << "A(&&)." << std::endl;
    }
};

void foo(A a) {
    std::cout << "p2:" << &a.v << std::endl;
    std::vector<A> vec;
    vec.push_back(std::move(a));
    std::cout << "p3:" << &a.v << std::endl;
    std::cout << "p4:" << &vec[0].v << std::endl;
}

int main() {
    // A a;
    // std::cout << "p1:" << &a.v << std::endl;
    // // foo(a);
    // foo(std::move(a));
    // A a1 = std::move(a);
    std::vector<int> vec = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    std::cout << (vec.data()) << std::endl;
    std::vector<int> vec1;
    vec1.swap(vec);
    std::cout << (vec1.data()) << std::endl;
    std::cout << (vec.data()) << std::endl;
}

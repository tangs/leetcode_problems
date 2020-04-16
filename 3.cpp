#include <iostream>

using namespace std;

class A {
 public:
    A() = default;
    virtual ~A() {
        cout << "call. A::~A()." << endl;
    }
};

class B : A {
 public:
    B() = default;
    ~B() {
        cout << "call. B::~B()." << endl;
    }
};

int main() {
    // B b;
    A* a = (A*)(new B());
    delete a;
}

#include <stdio.h>
#include <bitset>

void get(int data[9][9]) {
    data[1][1] = 100;
}

int main() {
    int data[9][9];
    data[1][1] = 10;
    get(data);
    
    printf("%d\n", data[1][1]);
    printf("%lu\n", sizeof(&data));
    printf("%lu %lu\n", sizeof(char&), sizeof(char&&));

    auto func = [] (int a, int b) {
        return a + b;
    };

    auto func1 = [data, b = data[0][0]] () {

    };

    auto func2 = [&data] () {

    };
    
    auto func3 = [b = data[0][0]] () {

    };
    
    auto func4 = [b = &data[0][0]] () {

    };

    func(3, 4);

    printf("%lu %lu %lu %lu %lu %lu\n", sizeof(func), sizeof(func1), 
        sizeof(func2), sizeof(&func1), sizeof(func3), sizeof(func4));
    printf("%lu %lu\n", sizeof(data), sizeof(&data));

    bool b1;
    bool b2[100];
    bool b3[1000];
    printf("%lu %lu %lu\n", sizeof(b1), sizeof(b2), sizeof(b3));

    std::bitset<1> bitset1;
    std::bitset<100> bitset2;
    std::bitset<1000> bitset3;
    printf("%lu %lu %lu\n", sizeof(bitset1), sizeof(bitset2), sizeof(bitset3));
}

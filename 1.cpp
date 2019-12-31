#include <stdio.h>

void get(int data[9][9]) {
    data[1][1] = 100;
}

int main() {
    int data[9][9];
    data[1][1] = 10;
    get(data);
    printf("%d\n", data[1][1]);
}

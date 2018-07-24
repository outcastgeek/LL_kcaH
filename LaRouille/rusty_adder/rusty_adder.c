
#include <stdio.h>

unsigned int add(unsigned int lhs, unsigned int rhs);

int main() {

    unsigned int lhs = 4;
    unsigned int rhs = 4;

    unsigned int res = add(lhs, rhs);

    printf("Rusty adding %u to %u equals %u\n", lhs, rhs, res);

    return 0;
}

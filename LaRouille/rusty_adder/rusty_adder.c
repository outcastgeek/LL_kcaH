
#include <stdio.h>

unsigned int add(unsigned int lhs, unsigned int rhs);

int calc_nearest_integer_of_square_root(float x);

int main() {

    unsigned int lhs = 4;
    unsigned int rhs = 4;

    unsigned int res = add(lhs, rhs);

    printf("Rusty adding %u to %u equals %u\n", lhs, rhs, res);

    float x = 9.2;
    int z = calc_nearest_integer_of_square_root(x);

    printf("Rusty calc_nearest_integer_of_square_root %f equals %i\n", x, z);

    return 0;
}


#include <stdio.h>

int main() {
    int int_var = 5;
    int *int_ptr;

    int_ptr = &int_var; // Put the address of int_var into int_ptr.

    printf("Address of int_var = %i is int_ptr = %p\n", int_var, int_ptr);
}

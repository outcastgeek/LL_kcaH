#include <iostream>

struct Vector{
    int sz; // number of elements
    double* elem; // pointer to elements
};

// The & in Vectir& indicates that we pass v by non-const reference so that vector_init can modify it
// The new operator allocates memory from area called the free store aka dynamic memory and heap, independent of scope
void vector_init(Vector& v, int s)
{
    v.elem = new double[s]; // allocate an array of s doubles; lives until destroyed with delete
    v.sz = s;
}

// We use .(dot) to access struct members through a name
// We use -> to access struct members through a pointer
void access_vec(Vector v, Vector& rv, Vector* pv)
{
    int i1 = v.sz; // access through name
    int i2 = rv.sz; // access through reference
    int i3 = pv->sz; // access through pointer

    std::cout << "access through name v.sz: " << i1 << std::endl;
    std::cout << "access through reference rv.sz: " << i2 << std::endl;
    std::cout << "access through pointer pv->sz: " << i3 << std::endl;
}

double read_and_sum(int s)
// read s integers from cin and return their sum; s is assumed to be positive
{
    Vector v;
    vector_init(v, s); // allocate elements for v

    access_vec(v, v, &v);

    std::cout << "Enter " << s << " integers" << std::endl;
    for(int i=0; i!=s;++i)
        std::cin >> v.elem[i]; // read into elements

    double sum = 0;
    for(int i=0; i!=s;++i)
        sum += v.elem[i]; // compute the sum of the elements

    return sum;
}

int main() {
    std::cout << "Enter a Vector Size: " << std::endl;
    int s;
    std::cin >> s;

    auto sum = read_and_sum(s);
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <future>

double comp4(std::vector<double>& v)
// spawn many tasks if v is large enough
{
    if (v.size()<1000) // is it worth using concurrency?
        return std::accumulate(v.begin(), v.end(), 0.0);

    auto v0 = &v[0];
    auto sz = v.size();

    auto accum = [](double *start, double *end) {
//        return std::accumulate(start, end, 0.0);
        return std::accumulate(start, end, 0.0, std::plus<>{});
    };

    auto f0 = std::async(accum, v0, v0+sz/4); // first quarter
    auto f1 = std::async(accum, v0+sz/4, v0+sz/2); // second quarter
    auto f2 = std::async(accum, v0+sz/2, v0+sz*3/4); // third quarter
    auto f3 = std::async(accum, v0+sz*3/4, v0+sz); // fourth quarter

    return f0.get() + f1.get() + f2.get() + f3.get();
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::cout << "Enter the vector length" << std::endl;
    auto vector_length = 200000000;
    std::cin >> vector_length;

    std::vector<std::future<int>> futures;
    for(int i = 0; i < vector_length; ++i) {
        futures.push_back (std::async([](int m) {return 2 * m;} , i));
    }
    for(auto &e : futures) {
        std::cout << "Times Two Result: " << e.get() << std::endl;
    }

    std::vector<double> v(vector_length);
    std::iota(std::begin(v), std::end(v), 0.0);
    auto result = comp4(v);
    std::cout << "Result: " << result << std::endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <future>
#include <vector>
#include <numeric>

template <class Iterator, class Function>
void parallel_for_each(Iterator first, Iterator last, Function f)
{
    const std::size_t length = std::distance(first, last);
    const std::size_t max_size = 25;

    if (length <= max_size)
    {
        std::for_each(first, last, f);
    }
    else
    {
        Iterator middle = first;
        std::advance(middle, length / 2);
        std::future<void> first_half_result = std::async(parallel_for_each<Iterator, Function>, first, middle, f);
        parallel_for_each(middle, last, f);
        first_half_result.get();
    }
}
int main()
{
    std::vector<int> v(100);
    std::iota(v.begin(), v.end(), 1);

    parallel_for_each(v.begin(), v.end(), [](int& val) {
        val *= 5;
        });
    for (const auto& val : v)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}
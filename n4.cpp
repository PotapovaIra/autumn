#include <iostream>
#include <vector>

void gen(int n)
{
    std::vector<int> num(n);
    for (auto i = 0; i <= n; i++)
    {
        num[i] = i;
    }
    auto next = true;
    while (next)
    {
        for (auto i = 0; i <= n; i++)
        {
            std::cout << num[i] << " ";
        }
        std::cout << std::endl;

        auto j = n - 1;
        while (num[j] > num[j + 1])
        {
            j--;
            if (j == 0)
            {
                next = false;
                break;
            }
        }

        if (next)
        {
            auto k = n;
            while (num[j] > num[k])
            {
                k--;
            }

            std::swap(num[j], num[k]);

            auto r = n;
            auto s = j + 1;
            while (r > s)
            {
                std::swap(num[r], num[s]);
                r--;
                s++;
            }
        }
    }
}

int main()
{
    auto n = 0;
    std::cout << "Enter: ";
    std::cin >> n;
    gen(n);
    return 0;
}
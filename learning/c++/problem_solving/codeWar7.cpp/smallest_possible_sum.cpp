#include <vector>
#include <numeric> // std::gcd

unsigned long long solution(const std::vector<unsigned long long>& arr)
{
    if (arr.empty()) return 0;
    unsigned long long g = 0;
    for (auto x : arr) g = std::gcd(g, x);
    return g * arr.size();
}

#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> input(5);
    for (int i=0; i<5; i++)
        std::cin >> input[i];

    auto sum = std::accumulate(input.begin(), input.end(), 0, [](int sum, int next)->int {
        return sum + next*next;
    });
    std::cout << sum%10;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, goal; std::cin >> N >> goal;
    std::vector<int> trees;
    while (N --> 0) {
        int temp; std::cin >> temp;
        trees.emplace_back(temp);
    }
    int begin = 0;
    int end = *std::max_element(trees.begin(), trees.end());

    while (true) {
        if (begin + 1 == end)
            break;
        long long sum = 0;
        int temp = (begin + end) / 2;
        for (const auto& it : trees) {
            if (it - temp >= 0)
                sum += it - temp;
        }
        if (sum > goal) begin = temp;
        else if (sum < goal) end = temp;
        else {
            begin = temp;
            break;
        }
    }

    if (goal == 0) std::cout << end << "\n";
    else std::cout << begin << "\n";

}
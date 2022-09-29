#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M; std::cin >> N >> M;
    std::vector<int> vec; int temp;
    vec.push_back(0);
    for (int i=1; i<=N; i++) {
        std::cin >> temp;
        vec.push_back(vec[i-1] + temp);
    }
    // 0 5 9 12 14 15
    int i, j;
    while (M --> 0) {
        std::cin >> i >> j;
        std::cout << vec[j] - vec[i-1] << "\n";
    }
}
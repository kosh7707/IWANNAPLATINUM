#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, K; std::cin >> N >> K;
    std::vector<int> coin;
    while (N --> 0) {
        int temp; std::cin >> temp;
        coin.push_back(temp);
    }

    int count = 0;
    int idx = coin.size() - 1;
    while (K != 0) {
        while (coin[idx] > K) idx--;
        count += K/coin[idx];
        K %= coin[idx];
    }
    std::cout << count;
}

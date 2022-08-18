#include <iostream>
#include <string>
#include <deque>


int factorial(int N) {
    int ret=1;
    for (int i=2; i<=N; i++)
        ret *= i;
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, K; std::cin >> N >> K;
    std::cout << factorial(N) / factorial(K) / factorial(N-K);

}
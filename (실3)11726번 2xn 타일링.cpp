#include <iostream>
#include <vector>

std::vector<int> vec = {1, 2, 3, 5, 8};
int fibo(int N) {
    for (int i=5; i<=N; i++) {
        vec.push_back( (vec[i-1] + vec[i-2]) % 10007);
    }
    return vec[N];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    std::cout << fibo(N-1);
}
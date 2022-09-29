#include <iostream>
#include <vector>

std::vector<int> vec = {1, 3, 5, 11, 21};
int fibo(int N) {
    for (int i=5; i<=N; i++) {
        if (i % 2 == 0) {
            vec.push_back( (vec[i-1] * 2 - 1) % 10007);
        }
        else {
            vec.push_back( (vec[i-1] * 2 + 1) % 10007);
        }
    }
    return vec[N];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 1, 3, 5, 11, 21, 43, 85, 171
    int N; std::cin >> N;
    std::cout << fibo(N-1);
}
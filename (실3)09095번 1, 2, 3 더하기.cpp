#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int dp[11] = {0, 1, 2, 4};
    int T; std::cin >> T;
    while (T --> 0) {
        int N; std::cin >> N;
        for (int i=4; i<=N; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        std::cout << dp[N] << "\n";
    }
}
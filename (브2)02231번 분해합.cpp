#include <iostream>
#include <deque>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    int answer = 0;
    for (int i=1; i<N; i++) {
        int temp = i;
        int sum = i;
        while (temp > 0) {
            sum += temp%10;
            temp /= 10;
        }
        if (sum == N) {
            answer = i;
            break;
        }
    }
    if (answer != N)
        std::cout << answer << "\n";
    else
        std::cout << 0 << "\n";



}

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T; std::cin >> T;
    long long arr[101] = {1, 1, 1, 2, 2, 3, 4
                    , 5, 7, 9};
    // 9 [9] --> 7 + 2 --> [8] + [4]
    // 12 [10] --> 9 + 3 --> [9] + [5]
    // 16 [11] --> 12 + 4 --> [10] + [6]
    for (int i=10; i<=100; i++)
        arr[i] = arr[i-1] + arr[i-5];
    while (T --> 0) {
        int N; std::cin >> N;
        std::cout << arr[N-1] << "\n";
    }
}
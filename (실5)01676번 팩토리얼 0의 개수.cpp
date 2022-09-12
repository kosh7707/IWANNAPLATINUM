#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N; std::cin >> N;
    int count_2 = 0;
    int count_5 = 0;
    for (int i=2; i<=N; i++) {
        int temp = i;
        while (temp % 2 == 0 or temp % 5 == 0) {
            if (temp % 2 == 0) {
                temp /= 2; count_2++;
            }
            if (temp % 5 == 0) {
                temp /= 5; count_5++;
            }
        }
    }
    std::cout << ((count_2 < count_5) ? count_2 : count_5) << "\n";
}


#include <iostream>
#include <iomanip>

int main() {

    int T;
    std::cin >> T;

    while (T --> 0) {
        int N;
        std::cin >> N;
        int C, C_sum = 0;
        float G, G_sum = 0.0;

        while (N --> 0) {
            std::cin >> C >> G;
            C_sum += C;
            G_sum += G * static_cast<float>(C);
        }
        std::cout << C_sum << " " << std::fixed << std::setprecision(1) << G_sum/static_cast<float>(C_sum) << "\n";
    }

    return 0;
}
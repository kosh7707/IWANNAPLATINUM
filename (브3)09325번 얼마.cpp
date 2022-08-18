#include <iostream>

int main() {
    int T;
    std::cin >> T;

    while (T --> 0) {
        int s, n;
        std::cin >> s >> n;
        while (n --> 0) {
            int q, p;
            std::cin >> q >> p;
            s += q*p;
        }
        std::cout << s << "\n";

    }

    return 0;
}
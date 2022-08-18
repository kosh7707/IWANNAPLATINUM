#include <iostream>
#include <cmath>

int main() {

    int M, N;
    int min = 0;
    int sum = 0;
    std::cin >> M >> N;
    for (int i=M; i<N+1; i++) {
        if (sqrt(i) == static_cast<int>(sqrt(i))) {
            sum += i;
            if (min == 0) min = i;
        }
    }

    if (min == 0) {
        std::cout << "-1";
    }
    else {
        std::cout << sum << "\n" << min << std::endl;
    }



    return 0;
}
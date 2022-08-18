#include <iostream>

int main() {

    int n, sum = 0;

    std::cin >> n;
    do {
        sum += n;
    } while(n --> 0);

    std::cout << sum << "\n";


    return 0;
}
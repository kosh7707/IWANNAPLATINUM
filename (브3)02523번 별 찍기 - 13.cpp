#include <iostream>

int main() {
    int N;
    std::cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<i+1; j++)
            std::cout << "*";
        std::cout << "\n";
    }
    for (int i=0; i<N-1; i++) {
        for (int j=0; j<N-i-1; j++)
            std::cout << "*";
        std::cout << "\n";
    }
    return 0;
}
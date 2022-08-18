#include <iostream>

int main() {
    int N;
    std::cin >> N;

    for(int i=0; i<N; i++) {
        for (int j=0; j<N-i-1; j++) {
            std::cout << " ";
        }
        for (int k=0; k<2*i+1; k++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}
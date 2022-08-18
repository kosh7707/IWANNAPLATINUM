#include <iostream>

int main() {
    int N;
    std::cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N-i-1; j++)
            std::cout << " ";
        for(int k=0; k<2*i+1; k++)
            std::cout << "*";
        std::cout << "\n";
    }

    for(int i=1; i<N; i++) {
        for(int k=0; k<i; k++)
            std::cout << " ";
        for(int j=0; j<2*(N-i)-1; j++)
            std::cout << "*";
        std::cout << "\n";
    }
    return 0;
}
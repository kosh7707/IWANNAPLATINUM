#include <iostream>

int main() {
    int N;
    std::cin >> N;

    for(int i=0; i<N; i++) {
        for(int k=0; k<i; k++)
            std::cout << " ";
        for(int j=0; j<2*(N-i)-1; j++)
            std::cout << "*";
        std::cout << "\n";
    }
    return 0;
}
#include <iostream>
#include <string>

int main() {

    int n;
    std::cin >> n;

    for (int i=n; i>=1; i--) {
        std::string stuff1(n-i, ' ');
        std::string stuff2(i, '*');
        std::cout << stuff1 << stuff2 << "\n";
    }

    return 0;
}
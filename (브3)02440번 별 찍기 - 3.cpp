#include <iostream>
#include <string>

int main() {

    int n;
    std::cin >> n;

    for (int i=n; i>=1; i--) {
        std::string stuff(i, '*');
        std::cout << stuff << "\n";
    }

    return 0;
}
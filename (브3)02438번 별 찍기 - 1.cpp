#include <iostream>
#include <string>

int main() {

    int n;
    std::cin >> n;

    for (int i=1; i<=n; i++) {
        std::string stuff(i, '*');
        std::cout << stuff << "\n";
    }

    return 0;
}
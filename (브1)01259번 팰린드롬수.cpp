#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s, temp;
    while (std::cin >> s and s != "0") {
        temp = s;
        std::reverse(temp.begin(), temp.end());
        if (temp == s)
            std::cout << "yes\n";
        else
            std::cout << "no\n";
    }
}
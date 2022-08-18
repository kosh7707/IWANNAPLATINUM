#include <iostream>
#include <string>

int main() {
    int N; std::cin >> N;
    int temp = 0;
    while (N != 0) {
        temp++;
        std::string temp2(std::to_string(temp));
        if (temp2.find("666") != std::string::npos)
            N--;
    }
    std::cout << temp;

}
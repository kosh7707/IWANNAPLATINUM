#include <iostream>
#include <string>
#include <queue>

int main() {
    std::string cmd;
    int N; std::cin >> N;
    std::queue<int> qu;
    while (N --> 0) {
        std::cin >> cmd;
        if (cmd == "push") {
            int temp; std::cin >> temp;
            qu.push(temp);
        }
        else if (cmd == "pop") {
            if (qu.empty()) std::cout << "-1\n";
            else {
                std::cout << qu.front() << std::endl;
                qu.pop();
            }
        }
        else if (cmd == "size") {
            std::cout << qu.size() << std::endl;
        }
        else if (cmd == "empty") {
            if (qu.empty()) std::cout << "1\n";
            else std::cout << "0\n";
        }
        else if (cmd == "front") {
            if (qu.empty()) std::cout << "-1\n";
            else {
                std::cout << qu.front() << std::endl;
            }
        }
        else if (cmd == "back") {
            if (qu.empty()) std::cout << "-1\n";
            else {
                std::cout << qu.back() << std::endl;
            }
        }
    }


}

#include <iostream>
#include <string>
#include <deque>

int main() {
    std::string cmd;
    int N; std::cin >> N;
    std::deque<int> dq;
    while (N --> 0) {
        std::cin >> cmd;
        if (cmd == "push_front") {
            int temp; std::cin >> temp;
            dq.push_front(temp);
        }
        else if (cmd == "push_back") {
            int temp; std::cin >> temp;
            dq.push_back(temp);
        }
        else if (cmd == "pop_front") {
            if (dq.empty()) std::cout << "-1\n";
            else {
                std::cout << dq.front() << std::endl;
                dq.pop_front();
            }
        }
        else if (cmd == "pop_back") {
            if (dq.empty()) std::cout << "-1\n";
            else {
                std::cout << dq.back() << std::endl;
                dq.pop_back();
            }
        }
        else if (cmd == "size") {
            std::cout << dq.size() << std::endl;
        }
        else if (cmd == "empty") {
            if (dq.empty()) std::cout << "1\n";
            else std::cout << "0\n";
        }
        else if (cmd == "front") {
            if (dq.empty()) std::cout << "-1\n";
            else {
                std::cout << dq.front() << std::endl;
            }
        }
        else if (cmd == "back") {
            if (dq.empty()) std::cout << "-1\n";
            else {
                std::cout << dq.back() << std::endl;
            }
        }
    }


}

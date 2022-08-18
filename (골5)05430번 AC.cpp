#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

std::deque<int> parsing(std::string raw_numbers) {
    std::deque<int> numbers;
    int begin = 1;
    while (begin < raw_numbers.length()-1){
        int end = begin+1;
        std::string temp_number{raw_numbers[begin]};
        while (raw_numbers[end] != ',' and raw_numbers[end] != ']') {
            temp_number += raw_numbers[end];
            end++;
        }
        numbers.push_back(std::stoi(temp_number));
        begin = end+1;
    }
    return numbers;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T; std::cin >> T;
    while (T --> 0) {
        std::string command; std::cin >> command;
        int N; std::cin >> N;
        std::string raw_numbers; std::cin >> raw_numbers;
        std::deque<int> numbers = parsing(raw_numbers);
        bool reverse = false;
        bool error = false;
        for (const auto& it : command) {
            if (it == 'R') {
                if (reverse) reverse = false;
                else reverse = true;
            }
            else {
                if (numbers.empty()) {
                    error = true;
                    break;
                }
                else {
                    if (reverse) numbers.pop_back();
                    else numbers.pop_front();
                }
            }
        }
        if (error) {
            std::cout << "error\n";
        }
        else {
            std::cout << "[";
            if (reverse) {
                for (auto elem = numbers.rbegin(); elem != numbers.rend(); elem++) {
                    if (elem != numbers.rbegin()) std::cout << "," << *elem;
                    else std::cout << *elem;
                }
            }
            else {
                for (auto elem = numbers.begin(); elem != numbers.end(); elem++) {
                    if (elem != numbers.begin()) std::cout << "," << *elem;
                    else std::cout << *elem;
                }
            }
            std::cout << "]\n";
        }

    }

}
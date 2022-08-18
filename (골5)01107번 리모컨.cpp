#include <iostream>
#include <vector>
#include <cmath>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M; std::cin >> N >> M;
    std::vector<int> out_buttons;

    while (M --> 0) {
        int temp; std::cin >> temp;
        out_buttons.push_back(temp);
    }

    int current_channel = 100;
    int temp_answer1 = abs(N-current_channel);
    int temp_answer2 = 500000;
    for (int i=0; i<=1000000; i++) {
        bool enable = true;
        std::string temp_str(std::to_string(i));
        for (auto button : out_buttons) {
            if (temp_str.find(std::to_string(button)) != std::string::npos) {
                enable = false;
                break;
            }
        }
        if (enable) {
            int temp = temp_str.length() + abs(N-i);;
            temp_answer2 = (temp < temp_answer2) ? temp : temp_answer2;
        }
    }

    std::cout << ((temp_answer1 < temp_answer2) ? temp_answer1 : temp_answer2) << "\n";



}
#include <iostream>
#include <deque>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    while (N --> 0) {
        int size, goal; std::cin >> size >> goal;
        std::deque<std::pair<int, int>> dq;
        for (int i=0; i<size; i++) {
            int temp; std::cin >> temp;
            dq.emplace_back(std::pair<int, int>(i, temp));
        }
        int answer = 1;
        while (true) {
            auto temp = dq.front();
            auto it = std::find_if(dq.begin(), dq.end(), [&temp](const auto& a) -> bool {
                return temp.second < a.second;
            });
            if (it == dq.end() and temp.first == goal)
                break;
            else if (it == dq.end()) {
                dq.pop_front();
                answer++;
            }
            else {
                auto temp2 = dq.front();
                dq.pop_front();
                dq.push_back(temp2);
            }

        }
        std::cout << answer << "\n";

    }

}
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    std::vector<int> vec;

    for (int i=0; i<N; i++) {
        int temp; std::cin >> temp;
        vec.emplace_back(temp);
    }
    std::sort(vec.begin(), vec.end());

    // 평균
    auto avg = std::accumulate(vec.begin(), vec.end(), 0.0) / N;
    std::cout << int(round(avg)) << "\n";

    // 중앙값
    std::cout << vec[(N-1)/2] << "\n";

    // 최빈값
    std::vector<std::pair<int, int>> mode;
    for (const auto& it : vec) {
        auto find_it = std::find_if(mode.begin(), mode.end(), [&it](std::pair<int, int> temp) -> bool {
            return temp.first == it;
        });
        if (find_it != mode.end()) {
            find_it->second++;
        }
        else {
            mode.emplace_back(std::pair<int, int>(it, 1));
        }
    }
    std::sort(mode.begin(), mode.end(), [](std::pair<int, int> pair1, std::pair<int, int> pair2) -> bool {
        if (pair1.second == pair2.second)
            return pair1.first < pair2.first;
        return pair1.second > pair2.second;
    });
    if (mode[0].second == mode[1].second)
        std::cout << mode[1].first << "\n";
    else
        std::cout << mode[0].first << "\n";

    // 범위
    std::cout << vec[N-1] - vec[0] << "\n";

}
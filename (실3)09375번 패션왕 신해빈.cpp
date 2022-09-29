#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T; std::cin >> T;
    while (T --> 0) {
        int N; std::cin >> N;
        std::unordered_map<std::string, int> um;
        while (N --> 0) {
            std::string temp;
            std::cin >> temp >> temp;
            if (um.find(temp) != um.end()) {
                um[temp] += 1;
            } else {
                um.insert({temp, 1});
            }
        }
        int answer = 1;
        for(const auto& it : um) {
            answer *= it.second + 1;
        }
        std::cout << answer - 1 << "\n";
    }

}
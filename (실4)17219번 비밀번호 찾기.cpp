#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M; std::cin >> N >> M;
    std::unordered_map<std::string, std::string> um;
    while (N --> 0) {
        std::string temp1, temp2;
        std::cin >> temp1 >> temp2;
        um.insert({temp1, temp2});
    }
    while (M --> 0) {
        std::string temp; std::cin >> temp;
        std::cout << um[temp] << "\n";
    }
}

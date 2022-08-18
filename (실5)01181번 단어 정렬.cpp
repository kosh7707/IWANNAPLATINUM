#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    int N; std::cin >> N;
    std::vector<std::string> dict;
    for (int i=0; i<N; i++) {
        std::string temp; std::cin >> temp;
        dict.emplace_back(temp);
    }
    std::sort(dict.begin(), dict.end(), [](const std::string& s1, const std::string& s2) -> bool {
        if (s1.size() < s2.size() or (s1.size() == s2.size() and s1 < s2))
            return true;
        return false;
    });
    dict.erase(std::unique(dict.begin(), dict.end()), dict.end());
    for (const auto& it : dict)
        std::cout << it << "\n";
}
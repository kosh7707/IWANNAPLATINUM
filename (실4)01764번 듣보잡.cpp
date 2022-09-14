#include <iostream>
#include <set>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M; std::cin >> N >> M;
    std::string temp;
    std::set<std::string> us;
    std::set<std::string> emeqhwkq;
    while (N --> 0) {
        std::cin >> temp;
        us.insert(temp);
    }
    int count = 0;
    while (M --> 0) {
        std::cin >> temp;
        if (us.find(temp) != us.end()) {
            count += 1;
            emeqhwkq.insert(temp);
        }
    }

    std::cout << count << "\n";
    for (const auto& it : emeqhwkq) {
        std::cout << it << "\n";
    }

}

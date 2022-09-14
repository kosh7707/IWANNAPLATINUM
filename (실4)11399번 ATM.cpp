#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    std::vector<int> person;
    while (N --> 0) {
        int temp; std::cin >> temp;
        person.push_back(temp);
    }
    std::sort(person.begin(), person.end());

    int answer = 0;
    for (int i=0; i<person.size(); i++) {
        answer += std::accumulate(person.begin(), person.begin() + i + 1, 0);
    }

    std::cout << answer << "\n";
}

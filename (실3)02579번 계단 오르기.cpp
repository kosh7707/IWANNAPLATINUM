#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    std::vector<int> stair;
    std::vector<int> answer(N);
    for (int i=0; i<N; i++) {
        int temp; std::cin >> temp;
        stair.push_back(temp);
    }
    answer[0] = stair[0];
    answer[1] = stair[0] + stair[1];
    answer[2] = std::max(stair[0] + stair[2], stair[1] + stair[2]);
    for (int i=3; i<N; i++) {
        answer[i] = std::max(answer[i-2] + stair[i], stair[i-1] + answer[i-3] + stair[i]);
    }
    std::cout << answer[N-1];
}

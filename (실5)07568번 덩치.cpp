#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    std::vector<int> weight;
    std::vector<int> height;
    std::vector<int> rank_list;

    for (int i=0; i<N; i++) {
        int temp_weight, temp_height;
        std::cin >> temp_weight >> temp_height;
        weight.emplace_back(temp_weight);
        height.emplace_back(temp_height);
    }

    for (int i=0; i<N; i++) {
        int rank = 1;
        for (int j=0; j<N; j++) {
            if (i == j) continue;
            if (weight[i] < weight[j] and height[i] < height[j])
                rank++;
        }
        rank_list.emplace_back(rank);
    }

    for (int i=0; i<N; i++)
        std::cout << rank_list[i] << " ";
}
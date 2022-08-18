#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    std::vector<int> vec(10001, 0);

    while (N --> 0) {
        short temp; std::cin >> temp;
        vec[temp]++;
    }

    for (short i=1; i<10001; i++) {
        while (vec[i] != 0) {
            std::cout << i << "\n";
            vec[i]--;
        }
    }


}
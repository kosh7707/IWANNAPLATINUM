#include <iostream>
#include <vector>

std::vector<int> count_0 {1, 0, 1, 1, 2, 3, 5};
std::vector<int> count_1 {0, 1, 1, 2, 3, 5, 8};

int count_0_calc(int n) {
    if (n <= count_0.size() - 1)
        return count_0[n];
    else {
        count_0.push_back(count_0_calc(n-1) + count_0_calc(n-2));
        return count_0_calc(n-1) + count_0_calc(n-2);
    }
}
int count_1_calc(int n) {
    if (n <= count_1.size() - 1)
        return count_1[n];
    else {
        count_1.push_back(count_1_calc(n-1) + count_1_calc(n-2));
        return count_1_calc(n-1) + count_1_calc(n-2);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    while (N --> 0) {
        int temp; std::cin >> temp;
        std::cout << count_0_calc(temp) << " " << count_1_calc(temp) << "\n";
    }

}
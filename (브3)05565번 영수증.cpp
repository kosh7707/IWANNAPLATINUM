#include <iostream>
#include <numeric>
#include <vector>

int main() {

    std::vector<int> vec;
    int sum;
    std::cin >> sum;

    int temp;
    for(int i=0; i<9; i++) {
        std::cin >> temp;
        vec.push_back(temp);
    }

    std::cout << sum - std::accumulate(vec.begin(), vec.end(), 0);

    return 0;
}
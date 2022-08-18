#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; std::cin >> N;
    std::unordered_map<int, int> map1;
    while (N --> 0) {
        int temp_key; std::cin >> temp_key;
        if (map1.find(temp_key) != map1.end()) map1[temp_key] += 1;
        else map1.insert({temp_key, 1});
    }

    int M; std::cin >> M;
    while (M --> 0) {
        int temp; std::cin >> temp;
        if (map1.find(temp) != map1.end()) std::cout << map1[temp] << " ";
        else std::cout << 0 << " ";
    }

}
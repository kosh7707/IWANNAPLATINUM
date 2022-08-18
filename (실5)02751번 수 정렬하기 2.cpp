#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; std::cin >> N;
    set<int> set1;
    while (N --> 0) {
        int temp; std::cin >> temp;
        set1.insert(temp);
    }

    for (const auto& it: set1)
        std::cout << it << "\n";
}
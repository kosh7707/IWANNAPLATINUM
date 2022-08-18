#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    set<int> a;
    std::cin >> N;
    while (N --> 0) {
        int temp; std::cin >> temp;
        a.insert(temp);
    }

    std::cin >> M;
    while (M --> 0) {
        int temp;
        std::cin >> temp;
        if (a.find(temp) != a.end())
            std::cout << "1\n";
        else
            std::cout << "0\n";
    }
}
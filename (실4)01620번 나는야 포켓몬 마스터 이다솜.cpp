#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::unordered_map<int, std::string> number_book;
    std::unordered_map<std::string, int> name_book;
    int N, M; std::cin >> N >> M;
    for (int i=1; i<=N; i++) {
        std::string temp; std::cin >> temp;
        number_book.insert({i, temp});
        name_book.insert({temp, i});
    }
    while (M --> 0) {
        std::string temp; std::cin >> temp;
        if (std::all_of(temp.begin(), temp.end(), [](char c) {return std::isdigit(c);}))
            std::cout << number_book[std::stoi(temp)] << "\n";
        else
            std::cout << name_book[temp] << "\n";
    }

}

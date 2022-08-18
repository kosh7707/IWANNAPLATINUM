#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> input(8);
    std::vector<int> ascending{1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> descending{8, 7, 6, 5, 4, 3, 2, 1};
    for (int i=0; i<8; i++)
        std::cin >> input[i];

    if (input == ascending)
        std::cout << "ascending\n";
    else if (input == descending)
        std::cout << "descending\n";
    else
        std::cout << "mixed\n";

}

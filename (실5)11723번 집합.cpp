#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int M; std::cin >> M;
    bool check[21] = {false, };

    while (M --> 0) {
        std::string command; std::cin >> command;
        if (command[0] == 'a' and command[1] == 'd') {
            int temp; std::cin >> temp;
            check[temp] = true;
        }
        else if (command[0] == 'r') {
            int temp; std::cin >> temp;
            check[temp] = false;
        }
        else if (command[0] == 'c') {
            int temp; std::cin >> temp;
            if (check[temp]) std::cout << "1\n";
            else std::cout << "0\n";
        }
        else if (command[0] == 't') {
            int temp; std::cin >> temp;
            if (check[temp]) check[temp] = false;
            else check[temp] = true;
        }
        else if (command[0] == 'a' and command[1] == 'l') {
            for(int i=1; i<=20; i++) {
                check[i] = true;
            }
        }
        else if (command[0] == 'e') {
            for(int i=1; i<=20; i++) {
                check[i] = false;
            }
        }

    }


}

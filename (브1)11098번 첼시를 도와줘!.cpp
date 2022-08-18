#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct Player{
    int price;
    std::string name;
};

Player make_player() {
    Player player;
    int price;
    std::string name;
    std::cin >> price >> name;
    player.price = price;
    player.name = name;
    return player;
}

bool compareA(const Player& player1, const Player& player2) {
    return player1.price < player2.price;
}

int main() {
    int test_case;
    int player_count;

    std::cin >> test_case;
    while (test_case --> 0) {
        std::cin >> player_count;
        std::vector<Player> player_list(player_count);

        for (int i=0; i<player_count; i++) {
            player_list.emplace_back(make_player());
        }
        auto MVP = *std::max_element(player_list.begin(), player_list.end(), compareA);
        std::cout << MVP.name << std::endl;
    }


    return 0;
}
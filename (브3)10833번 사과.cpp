#include <iostream>

int main() {
    int T;
    std::cin >> T;
    int sum = 0;
    int student, apple;
    while (T-->0) {
        std::cin >> student >> apple;
        sum += apple % student;
    }
    std::cout << sum;
    return 0;
}
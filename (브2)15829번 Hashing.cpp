#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; std::cin >> N;
    std::string str; std::cin >> str;

    long long sum = 0;
    long long temp = 1;
    for(int i=0; i<N; i++) {
        sum += ((str[i] - 'a' + 1) * temp) % 1234567891;
        temp = (temp*31) % 1234567891;
    }
    std::cout << sum % 1234567891;
}
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long int min, max;
    std::cin >> min >> max;

    long long int count = max - min + 1;
    bool visited[1000001] = {false};

    for (long long int i=2; i<=(long long int)sqrt(max); i++) {
        long long int temp = min/i/i;
        while (i*i*temp < min) temp++;
        while (i*i*temp >= min and i*i*temp <= max) {
            if (!visited[i*i*temp - min]) {
                visited[i*i*temp - min] = true;
                count -= 1;
            }
            temp += 1;
        }
    }
    std::cout << count << "\n";
}
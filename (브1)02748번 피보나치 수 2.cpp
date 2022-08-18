#include <iostream>
#include <vector>

static std::vector<long long int> memorial{0, 1};

long long int fibo(const int& n) {
    if (n == 1) return 1;
    else if (n == 0) return 0;
    else {
        if (memorial.size() > n)
            return memorial[n];
        else {
            memorial.push_back(fibo(n-1) + fibo(n-2));
            return fibo(n-1) + fibo(n-2);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fibo(n) << "\n";

    return 0;
}
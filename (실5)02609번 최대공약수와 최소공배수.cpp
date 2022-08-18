#include <iostream>

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * (b / gcd(a, b)) * gcd(a, b);
}

int main() {
    /*
     * you can use '<algorithm>' lib's std::__gcd to get lcm.
     */

    int a, b;
    std::cin >> a >> b;

    std::cout << gcd(a, b) << "\n";

    std::cout << lcm(a, b);

    return 0;
}
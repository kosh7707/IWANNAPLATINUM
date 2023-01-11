#include <iostream>

using namespace std;

long long a, b, c, k;
void solve1() {
    long long arr[33];
    arr[1] = a;
    for (int i=1; i<32; i++)
        arr[i+1] = (arr[i]*arr[i])%c;

    long long result = 1;
    int idx = 1;
    while (b > 0) {
        if (b & 0b1) {
            result *= arr[idx];
            result %= c;
        }
        idx++;
        b >>= 1;
    }
    cout << result;
}

long long power(long long b) {
    if (b == 0) return 1;
    if (b == 1) return a % c;

    k = power(b / 2) % c;
    if (b%2 == 0) return k * k % c;
    return k * k % c * a % c;
}

void solve2() {
    cout << power(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c;

    // solve1();
    solve2();
}
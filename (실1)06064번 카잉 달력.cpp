#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t --> 0) {
        // m, n, x, y
        int m, n, x, y; cin >> m >> n >> x >> y;
        int GCD = (m > n) ? gcd(m, n) : gcd(n, m);
        int LCM = m * n / GCD;
        int temp_x = x, temp_y = 0;
        while (temp_x <= LCM) {
            temp_y = (temp_x % n == 0) ? n : temp_x % n;
            if (temp_y == y)
                break;
            temp_x += m;
        }
        if (temp_y == y) cout << temp_x << endl;
        else cout << "-1" << endl;
    }
}
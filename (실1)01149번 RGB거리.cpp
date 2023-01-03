#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    int total[3] = {0, };
    int new_total[3] = {0, };
    int r, g, b;
    for (int i=0; i<N; i++) {
        cin >> r >> g >> b;
        if (i == 0) {
            total[0] = r;
            total[1] = g;
            total[2] = b;
        }
        else {
            new_total[0] = min(r + total[1], r + total[2]);
            new_total[1] = min(g + total[0], g + total[2]);
            new_total[2] = min(b + total[0], b + total[1]);
            total[0] = new_total[0]; total[1] = new_total[1]; total[2] = new_total[2];
        }
    }

    cout << min(min(total[0], total[1]), total[2]);
}
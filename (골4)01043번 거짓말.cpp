#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int parents[51];
vector<int> knowTruth;
vector<int> peoples[51];

int SimpleFind(int x) {
    if (parents[x] == x) return x;
    return x = SimpleFind(parents[x]);
}

void SimpleUnion(int x, int y) {
    x = SimpleFind(x);
    y = SimpleFind(y);
    parents[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i=0; i<k; i++) {
        int temp; cin >> temp;
        knowTruth.push_back(temp);
    }

    for (int i=1; i<=n; i++) parents[i] = i;

    for (int i=0; i<m; i++) {
        int p; cin >> p;
        int num, prev;
        for (int j=0; j<p; j++) {
            if (j == 0) cin >> num;
            else {
                prev = num;
                cin >> num;
                SimpleUnion(prev, num);
            }
            peoples[i].push_back(num);
        }
    }

    for (const auto& people : peoples) {
        bool flag = false;
        for (const auto& person : people) {
            if (flag) break;
            for (const auto& temp : knowTruth) {
                if (SimpleFind(person) == SimpleFind(temp)) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) m--;
    }
    cout << m;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solution1() {
    int N, M; cin >> N >> M;
    vector<pair<int, int>> ladders;
    int temp1, temp2;
    for (int i=0; i<N+M; i++) {
        cin >> temp1 >> temp2;
        ladders.push_back({temp1, temp2});
    }

    bool visited[101] = {false};
    queue<pair<int, int>> qu;
    qu.push({1, 0});
    while (!qu.empty()) {
        auto next = qu.front(); qu.pop();
        if (next.first == 100) {
            cout << next.second;
            exit(0);
        }
        if (!visited[next.first]) {
            visited[next.first] = true;
            for (int i=1; i<=6; i++) {
                auto it = find_if(ladders.begin(), ladders.end(), [&next, &i](pair<int, int> p) -> bool {
                    return p.first == next.first + i;
                });
                if (it != ladders.end())
                    qu.push({it->second, next.second+1});
                else
                    qu.push({next.first+i, next.second+1});
            }
        }
    }
}

void solution2() {
    int check[101];
    int warp[101];
    for (int i=1; i<=100; i++) {
        check[i] = -1;
        warp[i] = i;
    }
    int N, M, x, y; cin >> N >> M;
    for (int i=0; i<N+M; i++) {
        cin >> x >> y;
        warp[x] = y;
    }

    queue<int> qu;
    check[1] = 0;
    qu.push(1);

    while(!qu.empty()) {
        int top = qu.front(); qu.pop();
        if (top == 100) break;
        for (int i=1; i<=6; i++) {
            if (top + i > 100) break;
            int next = warp[top + i];
            if (check[next] == -1) {
                check[next] = check[top] + 1;
                qu.push(next);
            }
        }
    }
    cout << check[100] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // solution1();
    solution2();
}
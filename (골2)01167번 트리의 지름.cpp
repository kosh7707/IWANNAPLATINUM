#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> graph[100001];
bool visited[100001] = {false, };
int maxIdx = 0;
int maxValue = 0;

void dfs(int x, int dist) {
    if (visited[x]) return;
    if (dist > maxValue) {
        maxIdx = x;
        maxValue = dist;
    }
    visited[x] = true;
    for (auto it : graph[x])
        dfs(it.first, it.second + dist);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        // (node, weight)
        pair<int, int> vertex;
        int number, input;
        cin >> number;
        cin >> input;
        while (input != -1) {
            vertex.first = input;
            cin >> vertex.second;
            graph[number].push_back(vertex);
            cin >> input;
        }
    }
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    dfs(maxIdx, 0);
    cout << maxValue;
}
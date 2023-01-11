#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x, temp1, temp2, temp3, ans=0;

vector<int> dijkstra(int start, int V, const vector<pair<int, int>> adjacencyList[1001]) {
    vector<int> dist(V+1, 99999999);
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        int cost = -pq.top().first;
        // 기본적으로 우선순위큐는 내림차순 정렬임. 찾는 것은 제일 작은 cost이기에 -를 붙임
        // 혹은 priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>> pq;
        // 이걸 써야 함.
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;
        for (int i=0; i<adjacencyList[cur].size(); i++) {
            int nCost = cost + adjacencyList[cur][i].second;
            if (nCost < dist[adjacencyList[cur][i].first]) {
                dist[adjacencyList[cur][i].first] = nCost;
                pq.push({make_pair(-nCost, adjacencyList[cur][i].first)});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> x;
    vector<pair<int, int>> adjacencyList[1001];
    for (int i=1; i<=m; i++) {
        cin >> temp1 >> temp2 >> temp3;
        adjacencyList[temp1].push_back({temp2, temp3});
    }

    vector<int> dist[n+1];
    for (int i=1; i<=n; i++)
        dist[i] = dijkstra(i, n, adjacencyList);

    for (int i=1; i<=n; i++) {
        temp1 = dist[i][x] + dist[x][i];
        ans = (temp1 > ans) ? temp1 : ans;
    }
    cout << ans;
}
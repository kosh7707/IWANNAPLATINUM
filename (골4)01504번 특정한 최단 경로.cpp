#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 99999999
using namespace std;

int V, E, a, b, c, v1, v2, temp, ans=99999999;
vector<pair<int, int>> adj[801];
vector<int> dijkstra(int start) {
    vector<int> dist(V+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cost) continue;
        for(int i=0; i<adj[cur].size(); i++) {
            int nCost = cost + adj[cur][i].second;
            if (nCost < dist[adj[cur][i].first]) {
                dist[adj[cur][i].first] = nCost;
                pq.push({nCost, adj[cur][i].first});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V >> E;
    for (int i=1; i<=E; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    auto dist_1 = dijkstra(1);
    auto dist_v1 = dijkstra(v1);
    auto dist_v2 = dijkstra(v2);
    ans = min(dist_1[v1] + dist_v1[v2] + dist_v2[V], dist_1[v2] + dist_v2[v1] + dist_v1[V]);
    if (ans >= INF) cout << -1;
    else cout << ans;
}
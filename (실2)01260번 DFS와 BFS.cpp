#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> graph[1001];
bool visited1[1001];
bool visited2[1001];

void dfs(int V, bool visited[], const std::vector<int> graph[]) {
    visited[V] = true;
    std::cout << V << " ";
    for (const auto& it : graph[V]) {
        int next = it;
        if (!visited[next]) dfs(next, visited, graph);
    }
}

void bfs(int V, bool visited[], const std::vector<int> graph[]) {
    std::queue<int> q;
    q.push(V);
    visited[V] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        std::cout << x << " ";
        for (const auto& it : graph[x]) {
            int y = it;
            if(!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, V;
    std::cin >> N >> M >> V;

    while (M --> 0) {
        int temp1, temp2; std::cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }
    for (auto& it : graph) {
        std::sort(it.begin(), it.end());
    }
    dfs(V, visited1, graph); std::cout << "\n";
    bfs(V, visited2, graph); std::cout << "\n";
}


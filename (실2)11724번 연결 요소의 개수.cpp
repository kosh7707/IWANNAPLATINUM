#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[1001] = {false};
vector<int> graph[1001];

bool dfs(int N) {
    if (visited[N])
        return false;
    else {
        visited[N] = true;
        for (const auto& it : graph[N]) {
            int next = it;
            if (!visited[next]) dfs(next);
        }
    }
    return true;
}

bool bfs(int N) {
    if (visited[N])
        return false;
    else {
        std::queue<int> q;
        q.push(N);
        visited[N] = true;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for (const auto& it : graph[x]) {
                int next = it;
                if(!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        return true;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M; std::cin >> N >> M;
    while (M --> 0) {
        int temp1, temp2; cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }
    int count = 0;
    for (int i=1; i<=N; i++) {
        if (bfs(i))
            count += 1;
    }
    cout << count;
}
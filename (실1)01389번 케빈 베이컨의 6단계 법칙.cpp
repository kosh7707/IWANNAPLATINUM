#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> graph[101];
int N, M;
int bfs(int x) {
    std::vector<int> dist(N+1, -1);
    std::queue<int> qu;
    qu.push(x);
    dist[x] = 0;
    while (!qu.empty()) {
        int y = qu.front(); qu.pop();
        for(int i=0; i<graph[y].size(); i++) {
            int next = graph[y][i];
            if (dist[next] == -1) {
                dist[next] = dist[y] + 1;
                qu.push(next);
            }
        }
    }
    int sum = 0;
    for(int i=0; i<=N; i++) {
        sum += dist[i];
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    std::vector<int> answer(101, 10000000);

    while (M --> 0) {
        int temp1, temp2; std::cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }
    for(int i=1; i<N; i++)
        answer[i] = bfs(i);

    auto it = std::min_element(answer.begin(), answer.end());
    std::cout << std::distance(answer.begin(), it) << "\n";
}


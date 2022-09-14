#include <iostream>
#include <vector>
#include <queue>

std::vector<int> graph[101];
int N;
bool visited[101];
int count = 0;

void dfs(int start) {
    visited[start] = true;
    for (const auto& it : graph[start]) {
        if (!visited[it]) {
            count += 1;
            dfs(it);
        }
    }
}
void bfs(int start) {
    std::queue<int> qu;
    qu.push(start);
    visited[start] = true;
    while(!qu.empty()) {
        int x = qu.front();
        qu.pop();
        for(const auto& it : graph[x]) {
            if (!visited[it]) {
                qu.push(it);
                count += 1;
                visited[it] = true;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N;
    int M; std::cin >> M;
    while (M --> 0) {
        int temp1, temp2;
        std::cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }
    bfs(1);
    std::cout << count << "\n";
}

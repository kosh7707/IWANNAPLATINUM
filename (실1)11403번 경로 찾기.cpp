#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<int> graph[100];
int visited[100];

void dfs(int x) {
    for (int i=0; i<graph[x].size(); i++) {
        if (!visited[graph[x][i]]) {
            visited[graph[x][i]] = 1;
            dfs(graph[x][i]);
        }
    }
}

void solutionUsingDFS() {
    int N; cin >> N;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            int temp; cin >> temp;
            if (temp) graph[i].push_back(j);
        }

    for (int i=0; i<N; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i);
        for (int j=0; j<N; j++)
            cout << visited[j] << " ";
        cout << "\n";
    }
}

void solutionUsingFloydWarshall() {
    int N; cin >> N;
    int graph2[100][100];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> graph2[i][j];

    for(int k=0; k<N; k++)
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++) {
                if (graph2[i][k] and graph2[k][j])
                    graph2[i][j] = 1;
            }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cout << graph2[i][j] << " ";
        cout << "\n";
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // solutionUsingDFS();
    solutionUsingFloydWarshall();
}
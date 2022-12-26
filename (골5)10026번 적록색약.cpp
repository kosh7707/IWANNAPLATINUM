#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;

int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[101][101] = {false};

void r_g_b(int x, int y, vector<vector<char>>& vec) {
    visited[x][y] = true;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <= -1 or nx >= N or ny <= -1 or ny >= N or visited[nx][ny]) continue;
        if (vec[x][y] == vec[nx][ny])
            r_g_b(nx, ny, vec);
    }
}

void rg_b(int x, int y, vector<vector<char>>& vec) {
    visited[x][y] = true;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <= -1 or nx >= N or ny <= -1 or ny >= N or visited[nx][ny]) continue;
        if (vec[x][y] == vec[nx][ny] or !(vec[x][y] == 'B' or vec[nx][ny] == 'B'))
            rg_b(nx, ny, vec);
    }
}

int main() {
    int count1 = 0, count2 = 0;
    cin >> N;
    vector<vector<char>> vec(N, vector<char>(N));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cin >> vec[i][j];
    }
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if (!visited[i][j]) {
                count1 += 1;
                r_g_b(i, j, vec);
            }

    memset(visited, false, sizeof(visited));
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if (!visited[i][j]) {
                count2 += 1;
                rg_b(i, j, vec);
            }

    cout << count1 << " " << count2 << endl;
}
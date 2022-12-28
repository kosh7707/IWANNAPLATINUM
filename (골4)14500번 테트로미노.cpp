#include <iostream>
#include <vector>

using namespace std;

int N, M, ans=0;
int map[500][500];
bool visited[500][500] = {false};
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

void otherShape(int y, int x) {
    //ㅏ, ㅓ, ㅗ, ㅜ
    if (y+2 < N and x+1 < M)
        ans = max(ans, (map[y][x] + map[y+1][x] + map[y+2][x] + map[y+1][x+1]));
    if (y+2 < N and x-1 >= 0)
        ans = max(ans, (map[y][x] + map[y+1][x] + map[y+2][x] + map[y+1][x-1]));
    if (y-1 >= 0 and x+2 < M)
        ans = max(ans, (map[y][x] + map[y][x+1] + map[y][x+2] + map[y-1][x+1]));
    if (y+1 < N and x+2 < M)
        ans = max(ans, (map[y][x] + map[y][x+1] + map[y][x+2] + map[y+1][x+1]));
}

void dfs(int y, int x, int length, int score) {
    if (length == 3) {
        ans = max(ans, score);
        return;
    }
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 or ny < 0 or nx >= M or ny >= N or visited[ny][nx])
            continue;
        visited[ny][nx] = true;
        dfs(ny, nx, length+1, score+map[ny][nx]);
        visited[ny][nx] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> map[i][j];

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) {
            visited[i][j] = true;
            dfs(i, j, 0, map[i][j]);
            otherShape(i, j);
            visited[i][j] = false;
        }

    cout << ans << endl;

}
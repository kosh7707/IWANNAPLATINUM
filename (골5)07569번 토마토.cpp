#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
typedef struct {
    int x, y, z;
} point;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::queue<point> qu;
    int M, N, H; cin >> M >> N >> H;
    vector<vector<vector<int>>> vec(H, vector<vector<int>>(N, vector<int>(M, 0)));
    for (int i=0; i<H; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<M; k++) {
                cin >> vec[i][j][k];
                if (vec[i][j][k] == 1)
                    qu.push({k, j, i});
            }
        }
    }

    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    // (z, y, x)
    while (!qu.empty()) {
        int x = qu.front().x;
        int y = qu.front().y;
        int z = qu.front().z;
        qu.pop();
        for (int i=0; i<6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx >= 0 and nx < M and ny >= 0 and ny < N and nz >= 0 and nz < H) {
                if (vec[nz][ny][nx] == 0) {
                    vec[nz][ny][nx] = vec[z][y][x] + 1;
                    qu.push({nx, ny, nz});
                }
            }
        }
    }

    int ret = 0;
    for (int i=0; i<H; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<M; k++) {
                if (ret < vec[i][j][k]) ret = vec[i][j][k];
                if (vec[i][j][k] == 0) {
                    cout << "-1" << endl;
                    exit(0);
                }
            }
        }
    }
    cout << ret-1 << endl;
}
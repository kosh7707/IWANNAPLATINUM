#include <iostream>
#include <vector>

int M, N, K;

bool dfs(int x, int y, std::vector<std::vector<int>>& vec) {
    if (x <= -1 or x >= N or y <= -1 or y >= M) {
        return false;
    }
    if (vec[x][y] == 1) {
        vec[x][y] = 0;
        dfs(x-1, y, vec);
        dfs(x+1, y, vec);
        dfs(x, y-1, vec);
        dfs(x, y+1, vec);
        return true;
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;
    while (T --> 0) {
        std::cin >> M >> N >> K;
        std::vector<std::vector<int>> vec(N, std::vector<int>(M, 0));
        while (K --> 0) {
            int x, y;
            std::cin >> x >> y;
            vec[y][x] = 1;
        }
        int result = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (dfs(i, j, vec)) {
                    result += 1;
                }
            }
        }
        std::cout << result << "\n";
    }


}

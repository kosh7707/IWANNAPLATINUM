#include <iostream>
#include <vector>
using namespace std;
bool ValidationCheck(vector<vector<int>> vec, int y, int x, int N) {
    int standard = vec[y][x];
    for (int i=y; i<y+N; i++) {
        for (int j=x; j<x+N; j++) {
            if (vec[i][j] != standard) return false;
        }
    }
    return true;
}

void recursive(vector<vector<int>> vec, int y, int x, int N) {
    if (N == 2 and !ValidationCheck(vec, y, x, N)) {
        cout << "(";
        cout << vec[y][x] << vec[y][x+1] << vec[y+1][x] << vec[y+1][x+1];
        cout << ")";
    }
    else if (ValidationCheck(vec, y, x, N))
        cout << vec[y][x];
    else {
        cout << "(";
        recursive(vec, y, x, N/2);
        recursive(vec, y, x+N/2, N/2);
        recursive(vec, y+N/2, x, N/2);
        recursive(vec, y+N/2, x+N/2, N/2);
        cout << ")";
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> vec(N, vector(N, 0));

    for (int i=0; i<N; i++) {
        string temp; cin >> temp;
        for (int j=0; j<N; j++)
            vec[i][j] = temp[j] - '0';
    }

    recursive(vec, 0, 0, N);

}
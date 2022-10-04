#include <iostream>
#include <vector>
using namespace std;

int arr[2] = {0, 0};
bool ValidationCheck(const vector<vector<int>>& matrix, int y, int x, int N) {
    int standard = matrix[y][x];
    for (int i=y; i<y+N; i++) {
        for (int j=x; j<x+N; j++) {
            if (matrix[i][j] != standard)
                return false;
        }
    }
    return true;
}

void func(const vector<vector<int>>& matrix, int y, int x, int N) {
    if (ValidationCheck(matrix, y, x, N)) {
        arr[matrix[y][x]]+= 1;
    }
    else {
        func(matrix, y, x, N/2);
        func(matrix, y, x+N/2, N/2);
        func(matrix, y+N/2, x, N/2);
        func(matrix, y+N/2, x+N/2, N/2);
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cin >> matrix[i][j];
    }

    func(matrix, 0, 0, N);
    cout << arr[0] << endl;
    cout << arr[1] << endl;

}